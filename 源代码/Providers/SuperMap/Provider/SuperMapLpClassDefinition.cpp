/** \file	 SuperMapLpClassDefinition.cpp
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-5
*/
#include "SuperMap.h"

SuperMapLpClassDefinition::SuperMapLpClassDefinition(void)
{
}

SuperMapLpClassDefinition::~SuperMapLpClassDefinition(void)
{
}

SuperMapLpClassDefinition::SuperMapLpClassDefinition(
	SuperMapLpFeatureSchema *parentLpSchema, 
	SuperMapConnection *connection,
	UGC::UGDataset* pDataset,
	FdoClassDefinition* configLogicalClass)
:
	m_parentLpSchema(parentLpSchema),
	m_pDataset(pDataset)
{
	TRACE(_T("开始调用 SuperMapLpClassDefinition::SuperMapLpClassDefinition() 。\n"));

	VALIDATE_ARGUMENT(connection);
	m_connection = connection;   ////NOTE: weak reference
	// 初始化逻辑属性集合
	
	m_LpProperties = new SuperMapLpPropertyDefinitionCollection();
	
	if(NULL == pDataset)
	{
		ConvertLogicalToPhysical(connection, configLogicalClass); // 根据逻辑要素类创建物理数据集
	}
	else
	{
		ConvertPhysicalToLogical(connection, pDataset);  // 根据物理数据集创建逻辑要素类
	}	
	// 把该逻辑物理类加入到逻辑物理模式中
	FdoPtr<SuperMapLpClassDefinitionCollection> lpClasses = m_parentLpSchema->GetLpClasses();
	lpClasses->Add(this);

	TRACE(_T("结束调用 SuperMapLpClassDefinition::SuperMapLpClassDefinition() 。\n"));
}

void SuperMapLpClassDefinition::ConvertPhysicalToLogical(SuperMapConnection *connection,  UGC::UGDataset *pDataset)
{
	TRACE(_T("开始调用 SuperMapLpClassDefinition::ConvertPhysicalToLogical() 。\n"));

	// 确定逻辑类名
	if (m_pDataset == NULL)
		m_pDataset = pDataset;

	if (!m_pDataset->IsOpen())
		m_pDataset->Open();

	FdoStringP pClassName(SuperMapUtil::StringToWString(m_pDataset->GetName().Cstr()).c_str());
	FdoString* logicalClassName = pClassName.operator FdoString *();

	// 创建逻辑要素类
	m_logicalClassDefinition = FdoFeatureClass::Create(logicalClassName, L""); 
	
	///(modified by zhouxu 2008-1-3 )
	// 处理各种支持类型的数据集：点、线、面、文本、CAD、Image(分成矢量和栅格两大类进行处理)
	if(!m_pDataset->IsVector())
	{
		// 逻辑类是否抽象
		m_logicalClassDefinition->SetIsAbstract(false);

		///////////////////////////////////////////////////////////////////////////////
		UGC::UGDatasetRaster* pDatasetRaster = (UGC::UGDatasetRaster*)m_pDataset;
		VALIDATE_POINTER(pDatasetRaster);

		FdoPtr<FdoPropertyDefinitionCollection> logicalProperties = m_logicalClassDefinition->GetProperties();
		FdoPtr<FdoRasterPropertyDefinition> logicalRasterProp = ConvertPhysicalToLogicalRasterProperty(connection, pDatasetRaster);
		if(logicalRasterProp != NULL)
		{
			logicalProperties->Add(logicalRasterProp);
		}

		// 创建identity属性(通常精确指一个标识属性)
    	// 创建逻辑标识属性
		FdoPtr<FdoDataPropertyDefinition> pIdentityPropertyDefinition =
			FdoDataPropertyDefinition::Create(FEATID_PROPERTY, L"");
		pIdentityPropertyDefinition->SetDataType(FdoDataType_String);
		pIdentityPropertyDefinition->SetLength(256);
		//pIdentityPropertyDefinition->SetIsAutoGenerated(true); //(true);
	/*	pIdentityPropertyDefinition->SetNullable(false);
		pIdentityPropertyDefinition->SetReadOnly(true);*/

		FdoPtr<FdoDataPropertyDefinitionCollection> pIdentityProperties = m_logicalClassDefinition->GetIdentityProperties();
		VALIDATE_POINTER(pIdentityProperties);
		logicalProperties->Add(pIdentityPropertyDefinition);
		pIdentityProperties->Add(pIdentityPropertyDefinition);

		///创建一个空的几何属性(如果影像数据集和其他数据集混合时，Map3D总是提示影像数据类无几何属性，所以设置)
		// 获取逻辑几何属性名
		//FdoStringP logicalGeomPropertyName;
		//FdoStringP logicalGeomPropertyDescription;
		//// 建立缺省的Geometry字段
		//logicalGeomPropertyName = GEOMETRY_PROPERTY;
		//logicalGeomPropertyDescription = L"";
		//FdoPtr<FdoGeometricPropertyDefinition> pLogicalGeomProperty = 
		//	FdoGeometricPropertyDefinition::Create(logicalGeomPropertyName, logicalGeomPropertyDescription);
		//pLogicalGeomProperty->SetGeometryTypes(FdoGeometryType_Polygon);
		//logicalProperties->Add(pLogicalGeomProperty);
		//if(m_logicalClassDefinition->GetClassType() == FdoClassType_FeatureClass)
		//{
		//	FdoFeatureClass* logicalFeatureClass = static_cast<FdoFeatureClass*>(m_logicalClassDefinition.p);
		//	logicalFeatureClass->SetGeometryProperty(pLogicalGeomProperty);
		//}
		
		///创建并设置要素类的能力
		FdoClassCapabilitiesP classCapabilities = FdoClassCapabilities::Create(*m_logicalClassDefinition.p);
		classCapabilities->SetSupportsLocking(false);
		classCapabilities->SetSupportsLongTransactions(false);
		classCapabilities->SetSupportsWrite(false);
		m_logicalClassDefinition->SetCapabilities(classCapabilities);

		// 把影像类添加到影像模式中
		/*FdoPtr<FdoFeatureSchema> ImageSchema = m_parentLpSchema->GetImageSchema();
		FdoPtr<FdoClassCollection> logicalClasses = ImageSchema->GetClasses();
		logicalClasses->Add(m_logicalClassDefinition);*/
	}
	else
	{
		// 初始化逻辑类的类能力
		FdoPtr<FdoClassCapabilities> classCapabilities = FdoClassCapabilities::Create(*m_logicalClassDefinition.p);
		classCapabilities->SetSupportsLocking(false);
		classCapabilities->SetSupportsLongTransactions(false);
		classCapabilities->SetSupportsWrite(true); //暂时设为可写，UGC暂不支持判断数据集可写与否?

		m_logicalClassDefinition->SetCapabilities(classCapabilities);
		// 逻辑类是否抽象
		m_logicalClassDefinition->SetIsAbstract(false);

		//////////////////////////////////////////////////////////
		UGC::UGDatasetVector* pDatasetVector = (UGC::UGDatasetVector*)m_pDataset;

		// 获取记录集所有字段，遍历字段促发要素类属性的建立
		VALIDATE_POINTER(pDatasetVector);
		// added by zhoux 2007-11-28
		// 如果是文本数据集，则在逻辑类的属性中加一个名称为TEXT_PROPERTY，类型为FdoDataType_String的属性字段
		//modified by zhouxu 2008-4-28 //if(pDatasetVector->GetType() == UGC::UGDataset::Text )
		if(pDatasetVector->GetType() == UGC::UGDataset::Text || pDatasetVector->GetType() == UGC::UGDataset::CAD)
		{
			FdoPtr<FdoDataPropertyDefinition> logicalProperty1, logicalProperty2; // 存文本内容和文本大小的特殊字段

			//创建并设置要素类的文本内容字段
			FdoString* logicalPropertyName1 = TEXT_PROPERTY;
			FdoString* logicalPropertyDescription1 = L"";
			logicalProperty1 = FdoDataPropertyDefinition::Create(logicalPropertyName1, logicalPropertyDescription1);
			logicalProperty1->SetDataType(FdoDataType_String);
			logicalProperty1->SetReadOnly(false);
			logicalProperty1->SetNullable(false);
			logicalProperty1->SetIsAutoGenerated(false);
			//字符串类型需要设置长度
			logicalProperty1->SetLength(TEXT_LENGTH);

			//创建并设置要素类的文本长度字段
			FdoString* logicalPropertyName2 = TEXT_SIZE_PROPERTY;
			FdoString* logicalPropertyDescription2 = L"";
			logicalProperty2 = FdoDataPropertyDefinition::Create(logicalPropertyName2, logicalPropertyDescription2);
			logicalProperty2->SetDataType(FdoDataType_Double);
			logicalProperty2->SetReadOnly(false);
			logicalProperty2->SetNullable(false);
			logicalProperty2->SetIsAutoGenerated(false);

			//如果没有重复字段名再加这个字段
			FdoPtr<FdoPropertyDefinitionCollection> logicalProperties = m_logicalClassDefinition->GetProperties();
			if(!(logicalProperties->Contains(logicalProperty1->GetName())))
			{
				logicalProperties->Add(logicalProperty1);
			}
			if(!(logicalProperties->Contains(logicalProperty2->GetName())))
			{
				logicalProperties->Add(logicalProperty2);
			}
		}
		
		FdoInt32 fieldCount = pDatasetVector->GetFieldCount();
		
		//从配置文件判断是否需要读取Sm系统字段信息
		if(SuperMapConfig::m_IsReadSmField)
		{
			for(FdoInt32 i = 0; i < fieldCount; ++i)
			{
				UGC::UGFieldInfo FieldInfo;
				if(pDatasetVector->GetFieldInfo(i, FieldInfo))
				{
					if((FieldInfo.m_strName != "SmID") && (FieldInfo.m_strName != "SMID")) //对SmID以外的属性字段建立要素类的属性 （待讨论确定）
					{
						FdoPtr<SuperMapLpPropertyDefinition> pDataPropertyDefinition = 
							new SuperMapLpPropertyDefinition(this, pDatasetVector, &FieldInfo, NULL);
					}
				}
			}
		}
		else
		{
			for(FdoInt32 i = 0; i < fieldCount; ++i)
			{
				UGC::UGFieldInfo FieldInfo;
				if(pDatasetVector->GetFieldInfo(i, FieldInfo))
				{
					if((0 != strcmp("Sm",FieldInfo.m_strName.Mid(0,2)))
						&& 0 != strcmp("SM",FieldInfo.m_strName.Mid(0,2)))
					{
						FdoPtr<SuperMapLpPropertyDefinition> pDataPropertyDefinition = 
							new SuperMapLpPropertyDefinition(this, pDatasetVector, &FieldInfo, NULL);
					}
				}
			}
		}

		FdoPtr<FdoPropertyDefinitionCollection> logicalProperties = m_logicalClassDefinition->GetProperties();

		// 创建geometry属性（通常精确指一个几何属性）
		FdoPtr<FdoGeometricPropertyDefinition> logicalGeomProp = ConvertPhysicalToLogicalGeometryProperty(connection, pDatasetVector);
		if(logicalGeomProp != NULL)
		{
			logicalProperties->Add(logicalGeomProp);
			if(m_logicalClassDefinition->GetClassType() == FdoClassType_FeatureClass)
			{
				FdoFeatureClass* logicalFeatureClass = static_cast<FdoFeatureClass*>(m_logicalClassDefinition.p);
				logicalFeatureClass->SetGeometryProperty(logicalGeomProp);
			}
		}

		// 创建identity属性(通常精确指一个标识属性)
		FdoPtr<FdoDataPropertyDefinition> pLogicalIdentityProperty = ConvertPhysicalToLogicalIdentityProperty();
		FdoPtr<FdoDataPropertyDefinitionCollection> pIdentityProperties = m_logicalClassDefinition->GetIdentityProperties();
		VALIDATE_POINTER(pIdentityProperties);
		logicalProperties->Add(pLogicalIdentityProperty);
		pIdentityProperties->Add(pLogicalIdentityProperty);
	}

	// 把逻辑类添加到逻辑模式中
	FdoPtr<FdoFeatureSchema> logicalSchema = m_parentLpSchema->GetLogicalSchema();
	FdoPtr<FdoClassCollection> logicalClasses = logicalSchema->GetClasses();
	logicalClasses->Add(m_logicalClassDefinition);

	TRACE(_T("结束调用 SuperMapLpClassDefinition::ConvertPhysicalToLogical() 。\n"));
}

void SuperMapLpClassDefinition::ConvertLogicalToPhysical(SuperMapConnection* connection, FdoClassDefinition* configLogicalClass)
{
	// 这部分暂时没考虑投影的转换
	TRACE(_T("SuperMapLpClassDefinition::ConvertLogicalToPhysical()\n"));
	UGC::UGDataSource* pDataSource = connection->GetDataSource();    // 获取当前的连接数据源
	VALIDATE_POINTER(pDataSource);                                   
	UGC::UGDatasetVector* pDatasetVector = NULL;                     // 通过逻辑要素类创建的矢量数据集
	UGC::UGDatasetVectorInfo datasetVectorInfo;                      // 用于创建矢量数据集的信息
	FdoPtr<FdoClassDefinition> logicalClass;                         // 参数逻辑类的拷贝，防止操作过程中参数被改动
	FdoString* logicalClassName;                                     // 逻辑类名
	FdoPtr<FdoGeometricPropertyDefinition> geometry;                 // 逻辑要素类的几何属性，从它的类型判断应创建的矢量数据集类型
	FdoPtr<FdoPropertyDefinition> configLogicalProperty;             // 通过它创建矢量数据集的属性字段，对应UGC::UGFieldInfo
	FdoPtr<FdoPropertyDefinitionCollection> configLogicalProperties; // 参数逻辑类的属性集合
	FdoInt32 logicalPropertyCount;                                   // 参数逻辑类的属性个数

	VALIDATE_ARGUMENT(configLogicalClass);

	// 复制参数类的定义
	logicalClass = FdoCommonSchemaUtil::DeepCopyFdoClassDefinition(configLogicalClass);
	logicalClassName = logicalClass->GetName();
	if((NULL == logicalClassName) || (0 == wcslen(logicalClassName)))
		throw FdoException::Create(NlsMsgGet(SUPERMAP_CLASS_NAME_INVALID, "The class name '%l$ls' is invalid", logicalClassName));
	// 把逻辑要素类名赋给矢量数据集名
	datasetVectorInfo.m_strName = SuperMapUtil::WcharToString(logicalClassName).c_str();   

	// 如果该矢量数据集名在数据源中已存在，抛出异常提示
	if(NULL != pDataSource->GetDataset(datasetVectorInfo.m_strName))
		throw FdoException::Create(NlsMsgGet(SUPERMAP_DATASET_EXIST,"the dataset exist!"));

	// 获取要素类的几何属性
	configLogicalProperties = logicalClass->GetProperties();              // 此处初始化configLogicalProperties
	FdoPtr<FdoGeometricPropertyDefinition> logicalGeometryProperty;
	logicalPropertyCount = configLogicalProperties->GetCount();           // 此处初始化logicalPropertyCount
	for(FdoInt32 i = 0; i < logicalPropertyCount; ++i)
	{
		FdoPtr<FdoPropertyDefinition> logicalProperty = configLogicalProperties->GetItem(i);
		if(FdoPropertyType_GeometricProperty == logicalProperty->GetPropertyType())
		{
			if(geometry != NULL)
				throw FdoException::Create(NlsMsgGet(SUPERMAP_SCHEMA_EXCESSIVE_GEOMETRY, "The class '%l$ls'contains more than one geometry property.", logicalClassName));
			else
				geometry = static_cast<FdoGeometricPropertyDefinition*>(FDO_SAFE_ADDREF(logicalProperty.p));
		}
	}
	// 根据几何属性的类型来判断应创建什么类型的矢量数据集 (暂时只支持二维的几何类型，包括点，线，多线，面，多面)
	FdoInt32 geomTypeCount;
	FdoGeometryType* geomTypes = geometry->GetSpecificGeometryTypes(geomTypeCount);
	datasetVectorInfo.m_nType = FdoGeometryToUGDatasetType(
		geomTypes,
		geomTypeCount,
		geometry->GetHasElevation(),
		geometry->GetHasMeasure());

	// 根据datasetVectorInfo的信息在所连接的数据源中创建矢量数据集
	pDatasetVector = pDataSource->CreateDatasetVector(datasetVectorInfo);
	if(pDatasetVector == NULL)
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_DATASET_CREATED_FAILED, "'%l$ls' datasetvector created fail",logicalClassName));
	}

	// 获取要素类的标识属性字段，以便数据属性字段转化成物理数据集的属性字段时进行屏蔽
	FdoPtr<FdoDataPropertyDefinitionCollection> logicalIdProperties = logicalClass->GetIdentityProperties();

	// 根据要素类的属性创建矢量数据集的属性字段。
	for(FdoInt32 i = 0; i < logicalPropertyCount; ++i)
	{
		configLogicalProperty = configLogicalProperties->GetItem(i);
		// 几何属性已处理
		if(FdoPropertyType_GeometricProperty == configLogicalProperty->GetPropertyType())
			continue;
		else if(FdoPropertyType_DataProperty == configLogicalProperty->GetPropertyType())
		{
			FdoString* propertyName = configLogicalProperty->GetName();
			if(!(logicalIdProperties->Contains(propertyName)))  // 屏蔽标识属性字段，SmID自动生成
			{
				FdoPtr<SuperMapLpPropertyDefinition> lpProperty = new SuperMapLpPropertyDefinition(this, pDatasetVector, NULL, configLogicalProperty);
			}
		}
		else
		{
			// 此处当参数类含有对象、关联或栅格属性时是该忽略还是“抛出模式创建失败”异常？待确定
			throw FdoException::Create(NlsMsgGet(SUPERMAP_CREATED_FAILED,"Schema create failed."));
		}
	}

	// added by zhouxu 2008-09-26
	/*FdoPtr<FdoFeatureSchema> logicalSchema = m_parentLpSchema->GetLogicalSchema();
	FdoPtr<FdoClassCollection> logicalClasses = logicalSchema->GetClasses();
	bool bAlreadyInCollection = false;
	for(FdoInt32 i = 0; i < logicalClasses->GetCount() && !bAlreadyInCollection; ++i)
	{
		FdoPtr<FdoClassDefinition> logicalClass = logicalClasses->GetItem(i);
		if (0 == wcscmp (logicalClass->GetName(), m_logicalClassDefinition->GetName())) 
			bAlreadyInCollection = true;
	}
	if(!bAlreadyInCollection)
	{
		TRACE(_T("添加新的逻辑类！！！"));
		logicalClasses->Add(m_logicalClassDefinition);
	}*/
}

SuperMapLpPropertyDefinitionCollection* SuperMapLpClassDefinition::GetLpProperties(void) const
{
	return FDO_SAFE_ADDREF(m_LpProperties.p);
}

UGC::UGDataset* SuperMapLpClassDefinition::GetDataset(void)
{
	return m_pDataset;
}

FdoClassDefinition* SuperMapLpClassDefinition::GetLogicalClass(void)
{
	return FDO_SAFE_ADDREF(m_logicalClassDefinition.p);
}

void SuperMapLpClassDefinition::SetParent (SuperMapLpFeatureSchema* parent)
{
    m_parentLpSchema = parent; // weak reference
}

FdoString* SuperMapLpClassDefinition::GetName()
{
    return m_logicalClassDefinition == NULL ? L"" : m_logicalClassDefinition->GetName();
}

void SuperMapLpClassDefinition::Delete (SuperMapConnection* connection)
{
	//删除物理类
	UGC::UGDataset* pDataset = this->GetDataset();
	pDataset->Close();
	UGC::UGDataSource* pDataSource = connection->GetDataSource();
	pDataSource->DeleteDataset(pDataset->GetName());

	//从父逻辑物理类中移除逻辑物理类
	FdoPtr<SuperMapLpClassDefinitionCollection> lpClasses = m_parentLpSchema->GetLpClasses();
	lpClasses->Remove(this);

	//从父逻辑模式中移除逻辑类
	FdoPtr<FdoFeatureSchema> logicalSchema = m_parentLpSchema->GetLogicalSchema();
	FdoPtr<FdoClassCollection> logicalClasses = logicalSchema->GetClasses();
	FdoPtr<FdoClassDefinition> logicalClassDefinition = logicalClasses->FindItem(m_logicalClassDefinition->GetName());
	logicalClasses->Remove(logicalClassDefinition);
}

// 静态成员函数，用于自动生成逻辑类的标识属性(自动生成标识属性字段)
FdoDataPropertyDefinition* SuperMapLpClassDefinition::ConvertPhysicalToLogicalIdentityProperty()
{
	TRACE(_T("开始调用 SuperMapLpClassDefinition::ConvertPhysicalToLogicalIdentityProperty() 。\n"));

	// 创建逻辑标识属性名
	FdoStringP logicalIdentityPropertyName;
	FdoStringP logicalIdentityPropertyDescription;

	// 使用缺省名先创建一个标识属性字段（暂不知UGC如何从一矢量数据集获得其主键字段）
	logicalIdentityPropertyName = FEATID_PROPERTY;
	logicalIdentityPropertyDescription = L"" ;

	// 创建逻辑标识属性
	FdoPtr<FdoDataPropertyDefinition> pIdentityPropertyDefinition =
		FdoDataPropertyDefinition::Create(logicalIdentityPropertyName, logicalIdentityPropertyDescription);
	pIdentityPropertyDefinition->SetDataType(FdoDataType_Int32);
	pIdentityPropertyDefinition->SetIsAutoGenerated(true); //(true);
	pIdentityPropertyDefinition->SetNullable(false);
	pIdentityPropertyDefinition->SetReadOnly(true);

	TRACE(_T("结束调用 SuperMapLpClassDefinition::ConvertPhysicalToLogicalIdentityProperty() 。\n"));

	return FDO_SAFE_ADDREF(pIdentityPropertyDefinition.p);						   
}


// 静态成员函数，用于匹配物理数据集类型与要素类的几何属性类型
FdoGeometricPropertyDefinition* SuperMapLpClassDefinition::ConvertPhysicalToLogicalGeometryProperty(SuperMapConnection *connection, UGC::UGDatasetVector* pDatasetVector)
{
	TRACE(_T("开始调用 SuperMapLpClassDefinition::ConvertPhysicalToLogicalGeometryProperty() 。\n"));

	FdoGeometryType  geomTypesDest[30];
	FdoInt32 geomTypeCount = 0;
	bool has_z;
	bool has_m;

	VALIDATE_POINTER(pDatasetVector);

	if(!pDatasetVector->HasGeometry())
		return (NULL);

	FdoInt32 nDatasetType = pDatasetVector->GetType(); // 通过数据集类型来唯一确定其几何类型（对于点、线、面）

	if ( !(nDatasetType == UGC::UGDataset::Point 
							|| nDatasetType == UGC::UGDataset::Line 
							|| nDatasetType == UGC::UGDataset::Region
							|| nDatasetType == UGC::UGDataset::CAD 
							|| nDatasetType == UGC::UGDataset::Text
							))
		return NULL;

	// 获取逻辑几何属性名
	FdoStringP logicalGeomPropertyName;
	FdoStringP logicalGeomPropertyDescription;

	// 建立缺省的Geometry字段
	logicalGeomPropertyName = GEOMETRY_PROPERTY;
	logicalGeomPropertyDescription = L"";

	// 从物理数据集几何类型转换到逻辑几何属性类型
	switch(nDatasetType) 
	{
	case UGC::UGDataset::Point:
		geomTypesDest[0] = FdoGeometryType_Point;
		geomTypeCount = 1;
		has_z = false;
		has_m = false;
		break;
	case UGC::UGDataset::Line:
		geomTypesDest[0] = FdoGeometryType_LineString; // FdoGeometryType_CurveString?
		geomTypesDest[1] = FdoGeometryType_MultiLineString;
		geomTypeCount = 2;
		has_z = false;
		has_m = false;
		break;
	case UGC::UGDataset::Region:
		geomTypesDest[0] = FdoGeometryType_Polygon;
		geomTypeCount = 1;
		has_z = false;
		has_m = false;  // 只有在我们的路线数据集等中才有测量维
		break;
	case UGC::UGDataset::CAD:
		geomTypesDest[0] = FdoGeometryType_MultiGeometry;
		geomTypeCount = 1;
		has_z = false;
		has_m = false;
		break;
	// 将文本数据集转化成点状要素类进行处理
	case UGC::UGDataset::Text:
		geomTypesDest[0] = FdoGeometryType_Point;
		geomTypeCount = 1;
		has_z = false;
		has_m = false;
		break;
	default:
		throw FdoSchemaException::Create(NlsMsgGet(SUPERMAP_UNKNOWN_SHAPE_TYPE, "The shape type number '%1$d' is unknown.", nDatasetType));
	}
	
	// 创建逻辑几何属性
	FdoPtr<FdoGeometricPropertyDefinition> pLogicalGeomProperty = FdoGeometricPropertyDefinition::Create(logicalGeomPropertyName, logicalGeomPropertyDescription);
	pLogicalGeomProperty->SetSpecificGeometryTypes(geomTypesDest, geomTypeCount);
	pLogicalGeomProperty->SetReadOnly(false);
	pLogicalGeomProperty->SetHasElevation(has_z);
	pLogicalGeomProperty->SetHasMeasure(has_m);

	// 设置几何属性字段对应空间语义
	FdoStringP tmpCsysName;
	FdoStringP csysName;
	FdoPtr<SuperMapSpatialContextCollection> scColl = connection->GetSpatialContexts();
	FdoPtr<SuperMapSpatialContext> sc = scColl->GetItem(0);
	csysName = sc->GetName();   
	
	pLogicalGeomProperty->SetSpatialContextAssociation(csysName);

	return FDO_SAFE_ADDREF(pLogicalGeomProperty.p);
}

// 静态成员函数，用于匹配Fdo几何类型到物理数据集类型
UGC::UGDataset::DatasetType SuperMapLpClassDefinition::FdoGeometryToUGDatasetType(FdoGeometryType* geomTypes, FdoInt32 geomTypeCount, bool has_elevation, bool has_measure)
{
	//UGC::UGDataset::DatasetType nDatasetType;
	//// 可以转化为点数据集类型的情况
	//if((geomTypeCount == 1) && FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Point))
	//{
	//	if(has_elevation)
	//		throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z,"the provider not support dimentionality Z "));
	//	else if(has_measure)
	//		throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_M,"the provider not support dimentionality M "));
	//	else
	//		nDatasetType = UGC::UGDataset::Point;
	//}
	//// 可以转化为线数据集类型的情况
	//else if
	//	(
	//	((geomTypeCount == 2) 
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_LineString)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiLineString))
	//	||
	//	((geomTypeCount == 1)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_LineString))
	//	||
	//	((geomTypeCount == 1)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiLineString))
	//	)
	//{
	//	if(has_elevation)
	//		throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z,"the provider not support dimentionality Z "));
	//	else if(has_measure)
	//		throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_M,"the provider not support dimentionality M "));
	//	else
	//		nDatasetType = UGC::UGDataset::Line;
	//}
	//// 可以转化为面数据集的情况
	//else if
	//	(
	//	((geomTypeCount == 2)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Polygon)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPolygon))
	//	||
	//	((geomTypeCount == 1)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Polygon))
	//	||
	//	((geomTypeCount == 1)
	//	&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPolygon))
	//	)
	//{
	//	if(has_elevation)
	//		throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z,"the provider not support dimentionality Z "));
	//	else if(has_measure)
	//		throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_M,"the provider not support dimentionality M "));
	//	else
	//		nDatasetType = UGC::UGDataset::Region;
	//}
	//// 除以上情况以外的情况抛出异常，显示暂不支持的几何类型
	//else
	//{
	//    wchar_t buffer[1024];
 //       buffer[0] = '\0';

 //       for (int i=FdoGeometryType_None; i<=FdoGeometryType_MultiCurvePolygon; i++)
 //       {
 //           if (FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, (FdoGeometryType)i))
 //           {
 //               if ('\0' != buffer[0])
 //                   wcscat (buffer, L"|");
 //               wcscat (buffer, FdoCommonMiscUtil::FdoGeometryTypeToString((FdoGeometryType)i));
 //           }
 //       }

 //       throw FdoException::Create (NlsMsgGet(FDO_131_UNSUPPORTED_GEOMETRY_TYPE, "The '%1$ls' geometry type (or combination of types) is not supported.", buffer));
	//}
	//
	//return nDatasetType;

	//modified by zhouxu

	UGC::UGDataset::DatasetType nDatasetType;
	// 可以转化为点数据集类型的情况
	if(
		// BACKWARD-COMPABILITY-BEGIN:
		((geomTypeCount==2)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Point)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPoint))
		||
		// BACKWARD-COMPABILITY-END.
		((geomTypeCount == 1) 
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Point))
		||
		((geomTypeCount == 1)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPoint))
		)
	{
		if(has_elevation)
			throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z,"the provider not support dimentionality Z "));
		else if(has_measure)
			throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_M,"the provider not support dimentionality M "));
		else
			nDatasetType = UGC::UGDataset::Point;
	}
	// 可以转化为线数据集类型的情况
	else if
		(
		// BACKWARD-COMPABILITY-BEGIN:
		((geomTypeCount==4)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_LineString)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiLineString)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_CurveString)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiCurveString))
		||
		// BACKWARD-COMPABILITY-END.
		((geomTypeCount == 2) 
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_LineString)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiLineString))
		||
		((geomTypeCount == 1)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_LineString))
		||
		((geomTypeCount == 1)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiLineString))
		)
	{
		if(has_elevation)
			throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z,"the provider not support dimentionality Z "));
		else if(has_measure)
			throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_M,"the provider not support dimentionality M "));
		else
			nDatasetType = UGC::UGDataset::Line;
	}
	// 可以转化为面数据集的情况
	else if
		(
		// BACKWARD-COMPABILITY-BEGIN:
		((geomTypeCount==4)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Polygon)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPolygon)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_CurvePolygon)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiCurvePolygon))
		||
		// BACKWARD-COMPABILITY-END.
		((geomTypeCount == 2)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Polygon)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPolygon))
		||
		((geomTypeCount == 1)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_Polygon))
		||
		((geomTypeCount == 1)
		&& FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, FdoGeometryType_MultiPolygon))
		)
	{
		if(has_elevation)
			throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_Z,"the provider not support dimentionality Z "));
		else if(has_measure)
			throw FdoException::Create(NlsMsgGet(SUPERMAP_GEOMETRY_NOT_SUPPORTED_M,"the provider not support dimentionality M "));
		else
			nDatasetType = UGC::UGDataset::Region;
	}
	// 除以上情况以外的情况抛出异常，显示暂不支持的几何类型
	else
	{
		wchar_t buffer[1024];
		buffer[0] = '\0';

		for (int i=FdoGeometryType_None; i<=FdoGeometryType_MultiCurvePolygon; i++)
		{
			if (FdoCommonMiscUtil::ContainsGeomType(geomTypes, geomTypeCount, (FdoGeometryType)i))
			{
				if ('\0' != buffer[0])
					wcscat (buffer, L"|");
				wcscat (buffer, FdoCommonMiscUtil::FdoGeometryTypeToString((FdoGeometryType)i));
			}
		}

		throw FdoException::Create (NlsMsgGet(FDO_131_UNSUPPORTED_GEOMETRY_TYPE, "The '%1$ls' geometry type (or combination of types) is not supported.", buffer));
	}
	
	return nDatasetType;
}

FdoRasterPropertyDefinition* SuperMapLpClassDefinition::ConvertPhysicalToLogicalRasterProperty(SuperMapConnection* connection, UGC::UGDatasetRaster* pDatasetRaster)
{
	VALIDATE_POINTER(pDatasetRaster);
	FdoStringP logicalRasterPropertyName = RASTER_PROPERTY;
	FdoStringP logicalRasterPropertyDescription = L"";
	FdoPtr<FdoRasterPropertyDefinition> pLogicalRasterProp = FdoRasterPropertyDefinition::Create(logicalRasterPropertyName, logicalRasterPropertyDescription);

	// 设置栅格属性字段对应空间语义  
	FdoStringP csysName;
	FdoPtr<SuperMapSpatialContextCollection> scColl = connection->GetSpatialContexts();
	FdoPtr<SuperMapSpatialContext> sc = scColl->GetItem(0);
	csysName = sc->GetName();   
	pLogicalRasterProp->SetSpatialContextAssociation(csysName);

    // 设置栅格属性的相关值
	UGC::UGDatasetRasterInfo* pRasterInfo = pDatasetRaster->GetInfo();
	VALIDATE_POINTER(pRasterInfo);
	pLogicalRasterProp->SetDefaultImageXSize(pRasterInfo->m_nWidth);    //需检验
	pLogicalRasterProp->SetDefaultImageYSize(pRasterInfo->m_nHeight);
	pLogicalRasterProp->SetReadOnly(true);
	pLogicalRasterProp->SetNullable(false);

	FdoPtr<FdoRasterDataModel> pRasterDataModel = FdoRasterDataModel::Create();
	// TODO:: 改pRasterInfo->m_ePixelFormat 不匹配
	//pRasterDataModel->SetBitsPerPixel(24/*pRasterInfo->m_ePixelFormat*/); // 设置每个像素所占的位数
	////pRasterDataModel->SetTileSizeX(pRasterInfo->m_nWidth); // 设置块的大小
	////pRasterDataModel->SetTileSizeY(pRasterInfo->m_nHeight);

	//pRasterDataModel->SetDataModelType(FdoRasterDataModelType_RGB);
	//pRasterDataModel->SetOrganization(FdoRasterDataOrganization_Pixel);
	//pRasterDataModel->SetDataType(FdoRasterDataType_UnsignedInteger);

	pLogicalRasterProp->SetDefaultDataModel(pRasterDataModel);

	return FDO_SAFE_ADDREF(pLogicalRasterProp.p);                                                                                                     
}

