# GENERATED FILE DO NOT EDIT
# Class recieves callbacks
class ClientEventHandler:

	# ts3plugin_onConnectStatusChangeEvent(serverConnectionHandlerID, newStatus, errorNumber)
	def onConnectStatusChangeEvent(self, **kwargs):
		pass

	# ts3plugin_onNewChannelEvent(serverConnectionHandlerID, channelID, channelParentID)
	def onNewChannelEvent(self, **kwargs):
		pass

	# ts3plugin_onNewChannelCreatedEvent(serverConnectionHandlerID, channelID, channelParentID, invokerID, invokerName, invokerUniqueIdentifier)
	def onNewChannelCreatedEvent(self, **kwargs):
		pass

	# ts3plugin_onDelChannelEvent(serverConnectionHandlerID, channelID, invokerID, invokerName, invokerUniqueIdentifier)
	def onDelChannelEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelMoveEvent(serverConnectionHandlerID, channelID, newChannelParentID, invokerID, invokerName, invokerUniqueIdentifier)
	def onChannelMoveEvent(self, **kwargs):
		pass

	# ts3plugin_onUpdateChannelEvent(serverConnectionHandlerID, channelID)
	def onUpdateChannelEvent(self, **kwargs):
		pass

	# ts3plugin_onUpdateChannelEditedEvent(serverConnectionHandlerID, channelID, invokerID, invokerName, invokerUniqueIdentifier)
	def onUpdateChannelEditedEvent(self, **kwargs):
		pass

	# ts3plugin_onUpdateClientEvent(serverConnectionHandlerID, clientID, invokerID, invokerName, invokerUniqueIdentifier)
	def onUpdateClientEvent(self, **kwargs):
		pass

	# ts3plugin_onClientMoveEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, moveMessage)
	def onClientMoveEvent(self, **kwargs):
		pass

	# ts3plugin_onClientMoveSubscriptionEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility)
	def onClientMoveSubscriptionEvent(self, **kwargs):
		pass

	# ts3plugin_onClientMoveTimeoutEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, timeoutMessage)
	def onClientMoveTimeoutEvent(self, **kwargs):
		pass

	# ts3plugin_onClientMoveMovedEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, moverID, moverName, moverUniqueIdentifier, moveMessage)
	def onClientMoveMovedEvent(self, **kwargs):
		pass

	# ts3plugin_onClientKickFromChannelEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, kickerID, kickerName, kickerUniqueIdentifier, kickMessage)
	def onClientKickFromChannelEvent(self, **kwargs):
		pass

	# ts3plugin_onClientKickFromServerEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, kickerID, kickerName, kickerUniqueIdentifier, kickMessage)
	def onClientKickFromServerEvent(self, **kwargs):
		pass

	# ts3plugin_onClientIDsEvent(serverConnectionHandlerID, uniqueClientIdentifier, clientID, clientName)
	def onClientIDsEvent(self, **kwargs):
		pass

	# ts3plugin_onClientIDsFinishedEvent(serverConnectionHandlerID)
	def onClientIDsFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerEditedEvent(serverConnectionHandlerID, editerID, editerName, editerUniqueIdentifier)
	def onServerEditedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerUpdatedEvent(serverConnectionHandlerID)
	def onServerUpdatedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerErrorEvent(serverConnectionHandlerID, errorMessage, error, returnCode, extraMessage)
	def onServerErrorEvent(self, **kwargs):
		pass

	# ts3plugin_onServerStopEvent(serverConnectionHandlerID, shutdownMessage)
	def onServerStopEvent(self, **kwargs):
		pass

	# ts3plugin_onTextMessageEvent(serverConnectionHandlerID, targetMode, toID, fromID, fromName, fromUniqueIdentifier, message, ffIgnored)
	def onTextMessageEvent(self, **kwargs):
		pass

	# ts3plugin_onTalkStatusChangeEvent(serverConnectionHandlerID, status, isReceivedWhisper, clientID)
	def onTalkStatusChangeEvent(self, **kwargs):
		pass

	# ts3plugin_onConnectionInfoEvent(serverConnectionHandlerID, clientID)
	def onConnectionInfoEvent(self, **kwargs):
		pass

	# ts3plugin_onServerConnectionInfoEvent(serverConnectionHandlerID)
	def onServerConnectionInfoEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelSubscribeEvent(serverConnectionHandlerID, channelID)
	def onChannelSubscribeEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelSubscribeFinishedEvent(serverConnectionHandlerID)
	def onChannelSubscribeFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelUnsubscribeEvent(serverConnectionHandlerID, channelID)
	def onChannelUnsubscribeEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelUnsubscribeFinishedEvent(serverConnectionHandlerID)
	def onChannelUnsubscribeFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelDescriptionUpdateEvent(serverConnectionHandlerID, channelID)
	def onChannelDescriptionUpdateEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelPasswordChangedEvent(serverConnectionHandlerID, channelID)
	def onChannelPasswordChangedEvent(self, **kwargs):
		pass

	# ts3plugin_onPlaybackShutdownCompleteEvent(serverConnectionHandlerID)
	def onPlaybackShutdownCompleteEvent(self, **kwargs):
		pass

	# ts3plugin_onSoundDeviceListChangedEvent(modeID, playOrCap)
	def onSoundDeviceListChangedEvent(self, **kwargs):
		pass

	# ts3plugin_onEditPlaybackVoiceDataEvent(serverConnectionHandlerID, clientID, samples, sampleCount, channels)
	def onEditPlaybackVoiceDataEvent(self, **kwargs):
		pass

	# ts3plugin_onEditPostProcessVoiceDataEvent(serverConnectionHandlerID, clientID, samples, sampleCount, channels, channelSpeakerArray, channelFillMask)
	def onEditPostProcessVoiceDataEvent(self, **kwargs):
		pass

	# ts3plugin_onEditMixedPlaybackVoiceDataEvent(serverConnectionHandlerID, samples, sampleCount, channels, channelSpeakerArray, channelFillMask)
	def onEditMixedPlaybackVoiceDataEvent(self, **kwargs):
		pass

	# ts3plugin_onEditCapturedVoiceDataEvent(serverConnectionHandlerID, samples, sampleCount, channels, edited)
	def onEditCapturedVoiceDataEvent(self, **kwargs):
		pass

	# ts3plugin_onCustom3dRolloffCalculationClientEvent(serverConnectionHandlerID, clientID, distance, volume)
	def onCustom3dRolloffCalculationClientEvent(self, **kwargs):
		pass

	# ts3plugin_onCustom3dRolloffCalculationWaveEvent(serverConnectionHandlerID, waveHandle, distance, volume)
	def onCustom3dRolloffCalculationWaveEvent(self, **kwargs):
		pass

	# ts3plugin_onUserLoggingMessageEvent(logMessage, logLevel, logChannel, logID, logTime, completeLogString)
	def onUserLoggingMessageEvent(self, **kwargs):
		pass

	# ts3plugin_onClientBanFromServerEvent(serverConnectionHandlerID, clientID, oldChannelID, newChannelID, visibility, kickerID, kickerName, kickerUniqueIdentifier, time, kickMessage)
	def onClientBanFromServerEvent(self, **kwargs):
		pass

	# ts3plugin_onClientPokeEvent(serverConnectionHandlerID, fromClientID, pokerName, pokerUniqueIdentity, message, ffIgnored)
	def onClientPokeEvent(self, **kwargs):
		pass

	# ts3plugin_onClientSelfVariableUpdateEvent(serverConnectionHandlerID, flag, oldValue, newValue)
	def onClientSelfVariableUpdateEvent(self, **kwargs):
		pass

	# ts3plugin_onFileListEvent(serverConnectionHandlerID, channelID, path, name, size, datetime, type, incompletesize, returnCode)
	def onFileListEvent(self, **kwargs):
		pass

	# ts3plugin_onFileListFinishedEvent(serverConnectionHandlerID, channelID, path)
	def onFileListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onFileInfoEvent(serverConnectionHandlerID, channelID, name, size, datetime)
	def onFileInfoEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupListEvent(serverConnectionHandlerID, serverGroupID, name, type, iconID, saveDB)
	def onServerGroupListEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupListFinishedEvent(serverConnectionHandlerID)
	def onServerGroupListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupByClientIDEvent(serverConnectionHandlerID, name, serverGroupList, clientDatabaseID)
	def onServerGroupByClientIDEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupPermListEvent(serverConnectionHandlerID, serverGroupID, permissionID, permissionValue, permissionNegated, permissionSkip)
	def onServerGroupPermListEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupPermListFinishedEvent(serverConnectionHandlerID, serverGroupID)
	def onServerGroupPermListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupClientListEvent(serverConnectionHandlerID, serverGroupID, clientDatabaseID, clientNameIdentifier, clientUniqueID)
	def onServerGroupClientListEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelGroupListEvent(serverConnectionHandlerID, channelGroupID, name, type, iconID, saveDB)
	def onChannelGroupListEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelGroupListFinishedEvent(serverConnectionHandlerID)
	def onChannelGroupListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelGroupPermListEvent(serverConnectionHandlerID, channelGroupID, permissionID, permissionValue, permissionNegated, permissionSkip)
	def onChannelGroupPermListEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelGroupPermListFinishedEvent(serverConnectionHandlerID, channelGroupID)
	def onChannelGroupPermListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelPermListEvent(serverConnectionHandlerID, channelID, permissionID, permissionValue, permissionNegated, permissionSkip)
	def onChannelPermListEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelPermListFinishedEvent(serverConnectionHandlerID, channelID)
	def onChannelPermListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onClientPermListEvent(serverConnectionHandlerID, clientDatabaseID, permissionID, permissionValue, permissionNegated, permissionSkip)
	def onClientPermListEvent(self, **kwargs):
		pass

	# ts3plugin_onClientPermListFinishedEvent(serverConnectionHandlerID, clientDatabaseID)
	def onClientPermListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelClientPermListEvent(serverConnectionHandlerID, channelID, clientDatabaseID, permissionID, permissionValue, permissionNegated, permissionSkip)
	def onChannelClientPermListEvent(self, **kwargs):
		pass

	# ts3plugin_onChannelClientPermListFinishedEvent(serverConnectionHandlerID, channelID, clientDatabaseID)
	def onChannelClientPermListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onClientChannelGroupChangedEvent(serverConnectionHandlerID, channelGroupID, channelID, clientID, invokerClientID, invokerName, invokerUniqueIdentity)
	def onClientChannelGroupChangedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerPermissionErrorEvent(serverConnectionHandlerID, errorMessage, error, returnCode, failedPermissionID)
	def onServerPermissionErrorEvent(self, **kwargs):
		pass

	# ts3plugin_onPermissionListGroupEndIDEvent(serverConnectionHandlerID, groupEndID)
	def onPermissionListGroupEndIDEvent(self, **kwargs):
		pass

	# ts3plugin_onPermissionListEvent(serverConnectionHandlerID, permissionID, permissionName, permissionDescription)
	def onPermissionListEvent(self, **kwargs):
		pass

	# ts3plugin_onPermissionListFinishedEvent(serverConnectionHandlerID)
	def onPermissionListFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onPermissionOverviewEvent(serverConnectionHandlerID, clientDatabaseID, channelID, overviewType, overviewID1, overviewID2, permissionID, permissionValue, permissionNegated, permissionSkip)
	def onPermissionOverviewEvent(self, **kwargs):
		pass

	# ts3plugin_onPermissionOverviewFinishedEvent(serverConnectionHandlerID)
	def onPermissionOverviewFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupClientAddedEvent(serverConnectionHandlerID, clientID, clientName, clientUniqueIdentity, serverGroupID, invokerClientID, invokerName, invokerUniqueIdentity)
	def onServerGroupClientAddedEvent(self, **kwargs):
		pass

	# ts3plugin_onServerGroupClientDeletedEvent(serverConnectionHandlerID, clientID, clientName, clientUniqueIdentity, serverGroupID, invokerClientID, invokerName, invokerUniqueIdentity)
	def onServerGroupClientDeletedEvent(self, **kwargs):
		pass

	# ts3plugin_onClientNeededPermissionsEvent(serverConnectionHandlerID, permissionID, permissionValue)
	def onClientNeededPermissionsEvent(self, **kwargs):
		pass

	# ts3plugin_onClientNeededPermissionsFinishedEvent(serverConnectionHandlerID)
	def onClientNeededPermissionsFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onFileTransferStatusEvent(transferID, status, statusMessage, remotefileSize, serverConnectionHandlerID)
	def onFileTransferStatusEvent(self, **kwargs):
		pass

	# ts3plugin_onClientChatClosedEvent(serverConnectionHandlerID, clientID, clientUniqueIdentity)
	def onClientChatClosedEvent(self, **kwargs):
		pass

	# ts3plugin_onClientChatComposingEvent(serverConnectionHandlerID, clientID, clientUniqueIdentity)
	def onClientChatComposingEvent(self, **kwargs):
		pass

	# ts3plugin_onServerLogEvent(serverConnectionHandlerID, logMsg)
	def onServerLogEvent(self, **kwargs):
		pass

	# ts3plugin_onServerLogFinishedEvent(serverConnectionHandlerID, lastPos, fileSize)
	def onServerLogFinishedEvent(self, **kwargs):
		pass

	# ts3plugin_onMessageListEvent(serverConnectionHandlerID, messageID, fromClientUniqueIdentity, subject, timestamp, flagRead)
	def onMessageListEvent(self, **kwargs):
		pass

	# ts3plugin_onMessageGetEvent(serverConnectionHandlerID, messageID, fromClientUniqueIdentity, subject, message, timestamp)
	def onMessageGetEvent(self, **kwargs):
		pass

	# ts3plugin_onClientDBIDfromUIDEvent(serverConnectionHandlerID, uniqueClientIdentifier, clientDatabaseID)
	def onClientDBIDfromUIDEvent(self, **kwargs):
		pass

	# ts3plugin_onClientNamefromUIDEvent(serverConnectionHandlerID, uniqueClientIdentifier, clientDatabaseID, clientNickName)
	def onClientNamefromUIDEvent(self, **kwargs):
		pass

	# ts3plugin_onClientNamefromDBIDEvent(serverConnectionHandlerID, uniqueClientIdentifier, clientDatabaseID, clientNickName)
	def onClientNamefromDBIDEvent(self, **kwargs):
		pass

	# ts3plugin_onComplainListEvent(serverConnectionHandlerID, targetClientDatabaseID, targetClientNickName, fromClientDatabaseID, fromClientNickName, complainReason, timestamp)
	def onComplainListEvent(self, **kwargs):
		pass

	# ts3plugin_onBanListEvent(serverConnectionHandlerID, banid, ip, name, uid, creationTime, durationTime, invokerName, invokercldbid, invokeruid, reason, numberOfEnforcements, lastNickName)
	def onBanListEvent(self, **kwargs):
		pass

	# ts3plugin_onClientServerQueryLoginPasswordEvent(serverConnectionHandlerID, loginPassword)
	def onClientServerQueryLoginPasswordEvent(self, **kwargs):
		pass

	# ts3plugin_onPluginCommandEvent(serverConnectionHandlerID, pluginName, pluginCommand)
	def onPluginCommandEvent(self, **kwargs):
		pass

	# ts3plugin_onIncomingClientQueryEvent(serverConnectionHandlerID, commandText)
	def onIncomingClientQueryEvent(self, **kwargs):
		pass

	# ts3plugin_onServerTemporaryPasswordListEvent(serverConnectionHandlerID, clientNickname, uniqueClientIdentifier, description, password, timestampStart, timestampEnd, targetChannelID, targetChannelPW)
	def onServerTemporaryPasswordListEvent(self, **kwargs):
		pass

	# ts3plugin_onAvatarUpdated(serverConnectionHandlerID, clientID, avatarPath)
	def onAvatarUpdated(self, **kwargs):
		pass

	# ts3plugin_onMenuItemEvent(serverConnectionHandlerID, type, menuItemID, selectedItemID)
	def onMenuItemEvent(self, **kwargs):
		pass

	# ts3plugin_onHotkeyEvent(keyword)
	def onHotkeyEvent(self, **kwargs):
		pass

	# ts3plugin_onHotkeyRecordedEvent(keyword, key)
	def onHotkeyRecordedEvent(self, **kwargs):
		pass
