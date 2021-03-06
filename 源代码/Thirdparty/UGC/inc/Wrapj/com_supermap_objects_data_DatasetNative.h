/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_supermap_objects_data_DatasetNative */

#ifndef _Included_com_supermap_objects_data_DatasetNative
#define _Included_com_supermap_objects_data_DatasetNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_CheckOut
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1CheckOut
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_CheckIn
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1CheckIn
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_UndoCheckOut
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1UndoCheckOut
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Open
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Open
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Close
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_ComputeBounds
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1ComputeBounds
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetBoundsLeft
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetBoundsLeft
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetBoundsBottom
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetBoundsBottom
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetBoundsRight
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetBoundsRight
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetBoundsTop
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetBoundsTop
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetCanUpdate
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetCanUpdate
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDataSource
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDataSource
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDateCreated
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDateCreated
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDateLastUpdated
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDateLastUpdated
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDescription
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDescription
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetDescription
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetDescription
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetMaxZ
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetMaxZ
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetMinZ
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetMinZ
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetType
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetIsVector
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetIsVector
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetCharset
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetCharset
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetCharset
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetCharset
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetFieldCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetFieldCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetRecordCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetRecordCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetSubDataset
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetSubDataset
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDimension
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDimension
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_UpdateFieldByInt
 * Signature: (JLjava/lang/String;ILjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1UpdateFieldByInt
  (JNIEnv *, jclass, jlong, jstring, jint, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_UpdateFieldByString
 * Signature: (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1UpdateFieldByString
  (JNIEnv *, jclass, jlong, jstring, jstring, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_CopyField
 * Signature: (JLjava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1CopyField
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_BuildSpatialIndex
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1BuildSpatialIndex
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_CreateIndex
 * Signature: (JLjava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1CreateIndex
  (JNIEnv *, jclass, jlong, jstring, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_DropIndex
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1DropIndex
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_CreateField
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1CreateField
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_DeleteFieldByName
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1DeleteFieldByName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_DeleteFieldByIndex
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1DeleteFieldByIndex
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetRecordsetCount
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetRecordsetCount
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetFieldInfoByName
 * Signature: (JLjava/lang/String;J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetFieldInfoByName
  (JNIEnv *, jclass, jlong, jstring, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetFieldInfoByIndex
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetFieldInfoByIndex
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetFieldInfos
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetFieldInfos
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetFieldInfoByName
 * Signature: (JLjava/lang/String;J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetFieldInfoByName
  (JNIEnv *, jclass, jlong, jstring, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetFieldInfoByIndex
 * Signature: (JIJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetFieldInfoByIndex
  (JNIEnv *, jclass, jlong, jint, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Truncate
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Truncate
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_StatisticByDouble
 * Signature: (JLjava/lang/String;I)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1StatisticByDouble
  (JNIEnv *, jclass, jlong, jstring, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_StatisticByInt
 * Signature: (JLjava/lang/String;I)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1StatisticByInt
  (JNIEnv *, jclass, jlong, jstring, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_StatisticByLong
 * Signature: (JLjava/lang/String;I)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1StatisticByLong
  (JNIEnv *, jclass, jlong, jstring, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Append
 * Signature: (JJZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Append
  (JNIEnv *, jclass, jlong, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Resample
 * Signature: (JDZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Resample
  (JNIEnv *, jclass, jlong, jdouble, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetToleranceSmallPolygon
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetToleranceSmallPolygon
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetToleranceSmallPolygon
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetToleranceSmallPolygon
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetToleranceDangle
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetToleranceDangle
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetToleranceDangle
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetToleranceDangle
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetToleranceNodeSnap
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetToleranceNodeSnap
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetToleranceNodeSnap
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetToleranceNodeSnap
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetToleranceGrain
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetToleranceGrain
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetToleranceGrain
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetToleranceGrain
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetToleranceFuzzy
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetToleranceFuzzy
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetToleranceFuzzy
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetToleranceFuzzy
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Dissolve
 * Signature: (JLjava/lang/String;Z)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Dissolve
  (JNIEnv *, jclass, jlong, jstring, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_FindClosestGeometry
 * Signature: (JDD)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1FindClosestGeometry
  (JNIEnv *, jclass, jlong, jdouble, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Query
 * Signature: (JJ)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Query
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_QueryWithBounds
 * Signature: (JDDDDII)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1QueryWithBounds
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble, jdouble, jint, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_QueryWithIDs
 * Signature: (J[III)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1QueryWithIDs
  (JNIEnv *, jclass, jlong, jintArray, jint, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_QueryByDistanceWithGeometry
 * Signature: (JJDLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1QueryByDistanceWithGeometry
  (JNIEnv *, jclass, jlong, jlong, jdouble, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_QueryByDistanceWithPoint
 * Signature: (JDDDLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1QueryByDistanceWithPoint
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetPixelFormat
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetPixelFormat
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetPixelHeight
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetPixelHeight
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetPixelWidth
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetPixelWidth
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetResolutionX
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetResolutionX
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetResolutionY
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetResolutionY
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetPixelValue
 * Signature: (JII)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetPixelValue
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_AdjustBrightness
 * Signature: (JD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1AdjustBrightness
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_AdjustContrast
 * Signature: (JD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1AdjustContrast
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_BuildPyramid
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1BuildPyramid
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_ExportImg
 * Signature: (JLjava/lang/String;IZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1ExportImg
  (JNIEnv *, jclass, jlong, jstring, jint, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetHistogram
 * Signature: (J)I
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetHistogram
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Negate
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Negate
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Register
 * Signature: (JDDDD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Register
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_RegisterByRect
 * Signature: (JDDDD)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1RegisterByRect
  (JNIEnv *, jclass, jlong, jdouble, jdouble, jdouble, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_RegisterByFile
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1RegisterByFile
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_ShowHistogram
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1ShowHistogram
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Smooth
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Smooth
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetEncodedType
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetEncodedType
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetEncodedType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetEncodedType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_AppendRaster
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1AppendRaster
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDefinition
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDefinition
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetHasPrymaid
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetHasPrymaid
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetPixel
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetPixel
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetValue
 * Signature: (JII)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetValue
  (JNIEnv *, jclass, jlong, jint, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_RemovePyramid
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1RemovePyramid
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetPixel
 * Signature: (JIII)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetPixel
  (JNIEnv *, jclass, jlong, jint, jint, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetValue
 * Signature: (JIID)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetValue
  (JNIEnv *, jclass, jlong, jint, jint, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_BuildHierarchicalSpatialIndex
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1BuildHierarchicalSpatialIndex
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_ClearRecordsets
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1ClearRecordsets
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Flush
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Flush
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetCacheMode
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetCacheMode
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetHasGeometry
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetHasGeometry
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetLongTransaction
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetLongTransaction
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetMapLibrary
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetMapLibrary
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetOptions1
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetOptions1
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetOptions2
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetOptions2
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetParentDataset
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetParentDataset
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetSequence
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetSequence
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetSpatialIndexDirty
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetSpatialIndexDirty
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetTableName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetTableName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetTolerance
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetTolerance
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetUserLock
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetUserLock
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_IsAvailableFieldName
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1IsAvailableFieldName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_Rename
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1Rename
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetLongTransaction
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetLongTransaction
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetMapLibrary
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetMapLibrary
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetOptions
 * Signature: (JIZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetOptions
  (JNIEnv *, jclass, jlong, jint, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetSequence
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetSequence
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetUserLock
 * Signature: (JZ)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetUserLock
  (JNIEnv *, jclass, jlong, jboolean);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetDangle
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetDangle
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetExtend
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetExtend
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetGrain
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetGrain
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetNodeSnap
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetNodeSnap
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_GetSmallPolygon
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1GetSmallPolygon
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_IsEmpty
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1IsEmpty
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetDangle
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetDangle
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetDefault
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetDefault
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetExtend
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetExtend
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetGrain
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetGrain
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetNodeSnap
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetNodeSnap
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_SetSmallPolygon
 * Signature: (JD)V
 */
JNIEXPORT void JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1SetSmallPolygon
  (JNIEnv *, jclass, jlong, jdouble);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_PJForwardVector
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1PJForwardVector
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_PJInverseVector
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1PJInverseVector
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_supermap_objects_data_DatasetNative
 * Method:    jni_PJTranslateVector
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_supermap_objects_data_DatasetNative_jni_1PJTranslateVector
  (JNIEnv *, jclass, jlong, jlong);

#ifdef __cplusplus
}
#endif
#endif
