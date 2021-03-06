#ifndef _ICREATELONGTRANSACTIONCHECKPOINT_H_
#define _ICREATELONGTRANSACTIONCHECKPOINT_H_
//

//
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifdef _WIN32
#pragma once
#endif

#include <FdoStd.h>
#include <Fdo/Connections/IConnection.h>
#include <Fdo/Commands/ICommand.h>
#include <Fdo/Commands/LongTransaction/LongTransactionConstants.h>

/// \brief
/// The FdoICreateLongTransactionCheckpoint interface defines the
/// CreateLongTransactionCheckpoint command, which allows the user to create a
/// checkpoint for any long transaction to which the user has the access privileges.
class FdoICreateLongTransactionCheckpoint : public FdoICommand
{
    friend class FdoIConnection;

public:
    /// \brief
    /// Gets the name of the long transaction for which a checkpoint should
    /// be created.
    /// 
    /// \return
    /// Returns the long transaction name
    /// 
    FDO_API virtual FdoString* GetLongTransactionName() = 0;

    /// \brief
    /// Sets the name of the long transaction for which a checkpoint should
    /// be created.
    /// 
    /// \param value 
    /// Input the name of the long transaction
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetLongTransactionName(FdoString* value) = 0;

    /// \brief
    /// Gets the name of the checkpoint to be created for the named long
    /// transaction.
    /// 
    /// \return
    /// Returns the checkpoint name
    /// 
    FDO_API virtual FdoString* GetCheckpointName() = 0;

    /// \brief
    /// Sets the name of the checkpoint to be created for the named long
    /// transaction.
    /// 
    /// \param value 
    /// Input the checkpoint name
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetCheckpointName(FdoString* value) = 0;

    /// \brief
    /// Gets the description of the checkpoint to be created for the named
    /// long transaction.
    /// 
    /// \return
    /// Returns the description of the checkpoint
    /// 
    FDO_API virtual FdoString* GetCheckpointDescription() = 0;

    /// \brief
    /// Sets the description of the checkpoint to be created for the named
    /// long transaction.
    /// 
    /// \param value 
    /// Input the description of the checkpoint
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void SetCheckpointDescription(FdoString* value) = 0;

    /// \brief
    /// Executes the CreateLongTransactionCheckpoint command.
    /// 
    /// \return
    /// Returns nothing
    /// 
    FDO_API virtual void Execute() = 0;
};
#endif


