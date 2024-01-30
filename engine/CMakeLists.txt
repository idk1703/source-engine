set(PROJECT engine)

set(SOURCES
	$<$<BOOL:${DEDICATED}>:cl_null.cpp>			# [$DEDICATED]
	socketcreator.cpp
	clientframe.cpp
	decal_clip.cpp
	demofile.cpp
	DevShotGenerator.cpp
	OcclusionSystem.cpp
	tmessage.cpp

	baseclient.cpp
	baseclientstate.cpp
	cbenchmark.cpp

	console.cpp

	render_pch.cpp

	decals.cpp
	disp.cpp
	disp_interface.cpp
	disp_mapload.cpp
	gl_draw.cpp
	gl_rsurf.cpp
	gl_shader.cpp

	decals.cpp
	disp.cpp
	disp_interface.cpp
	disp_mapload.cpp
	gl_draw.cpp
	gl_rsurf.cpp
	gl_shader.cpp

	l_studio.cpp
	matsys_interface.cpp
	modelloader.cpp
	Overlay.cpp
	r_decal.cpp
	r_linefile.cpp

	server_pch.cpp

	sv_ipratelimit.cpp
	sv_rcon.cpp
	sv_steamauth.cpp
	sv_uploaddata.cpp
	sv_uploadgamestats.cpp
	vengineserver_impl.cpp

	sv_main.cpp
	sv_client.cpp
	sv_ents_write.cpp
	sv_filter.cpp
	sv_framesnapshot.cpp
	sv_log.cpp
	sv_packedentities.cpp
	sv_plugin.cpp
	sv_precache.cpp
	sv_redirect.cpp
	sv_remoteaccess.cpp

	baseautocompletefilelist.cpp
	baseserver.cpp
	bitbuf_errorhandler.cpp
	${SRCDIR}/public/blockingudpsocket.cpp
	${SRCDIR}/public/bsptreedata.cpp
	${SRCDIR}/public/builddisp.cpp
	changeframelist.cpp
	checksum_engine.cpp
	ccs.cpp
	clockdriftmgr.cpp

	cl_check_process.cpp
	cmd.cpp
	cmodel.cpp
	cmodel_bsp.cpp
	cmodel_disp.cpp
	${SRCDIR}/public/collisionutils.cpp
	common.cpp
	${SRCDIR}/public/crtmemdebug.cpp
	cvar.cpp
	${SRCDIR}/public/disp_common.cpp
	disp_defs.cpp
	disp_helpers.cpp
	${SRCDIR}/public/disp_powerinfo.cpp
	${SRCDIR}/public/dispcoll_common.cpp
	DownloadListGenerator.cpp
	dt.cpp
	dt_common_eng.cpp
	dt_encode.cpp
	dt_instrumentation.cpp
	dt_instrumentation_server.cpp
	dt_localtransfer.cpp
	${SRCDIR}/public/dt_recv.cpp
	dt_recv_decoder.cpp
	dt_recv_eng.cpp
	${SRCDIR}/public/dt_send.cpp
	dt_send_eng.cpp
	dt_stack.cpp
	dt_test.cpp
	${SRCDIR}/public/dt_utlvector_common.cpp
	${SRCDIR}/public/dt_utlvector_recv.cpp
	${SRCDIR}/public/dt_utlvector_send.cpp
	enginesingleuserfilter.cpp
	enginestats.cpp
	enginethreads.cpp
	enginetrace.cpp
	filesystem_engine.cpp
	${SRCDIR}/public/filesystem_helpers.cpp
	${SRCDIR}/public/filesystem_init.cpp
	filetransfermgr.cpp
	GameEventManager.cpp
	GameEventManagerOld.cpp
	gametrace_engine.cpp
	hltvclient.cpp
	hltvclientstate.cpp
	hltvdemo.cpp
	hltvserver.cpp
	hltvtest.cpp
	host.cpp
	host_cmd.cpp
	host_listmaps.cpp
	host_phonehome.cpp
	host_state.cpp
	initmathlib.cpp
	${SRCDIR}/common/language.cpp
	LocalNetworkBackdoor.cpp

	${SRCDIR}/public/lumpfiles.cpp
	MapReslistGenerator.cpp

	materialproxyfactory.cpp
	mem_fgets.cpp
	mod_vis.cpp
	ModelInfo.cpp
	net_chan.cpp
	net_synctags.cpp
	net_ws.cpp
	net_ws_queued_packet_sender.cpp
	${SRCDIR}/common/netmessages.cpp
	${SRCDIR}/common/steamid.cpp
	networkstringtable.cpp
	NetworkStringTableItem.cpp
	networkstringtableclient.cpp
	networkstringtableserver.cpp
	${SRCDIR}/public/networkvar.cpp
	packed_entity.cpp
	pure_server.cpp
	pr_edict.cpp
	precache.cpp
	quakedef.cpp
	randomstream.cpp
	${SRCDIR}/common/randoverride.cpp
	${SRCDIR}/public/registry.cpp
	engine_replay_int.cpp
	replay_internal.cpp
	replaydemo.cpp

	replayserver.cpp
	${SRCDIR}/public/sentence.cpp

	sound_shared.cpp
	spatialpartition.cpp
	staticpropmgr.cpp
	${SRCDIR}/public/studio.cpp
	sys_dll.cpp
	sys_dll2.cpp

	sys_engine.cpp

	$<$<AND:${WINDOWS},${DEDICATED}>:sys_wind_null.cpp>
	$<$<BOOL:${LINUX}>:sys_linuxwind.cpp>	# [$POSIX]

	testscriptmgr.cpp
	traceinit.cpp
	${SRCDIR}/public/vallocator.cpp
	voiceserver_impl.cpp
	vprof_engine.cpp
	vprof_record.cpp
	world.cpp
	${SRCDIR}/public/XZip.cpp
	${SRCDIR}/public/XUnzip.cpp
	zone.cpp
	cheatcodes.cpp
	${SRCDIR}/public/editor_sendcommand.cpp
	keys.cpp
	${SRCDIR}/public/scratchpad3d.cpp
	servermsghandler.cpp
	${SRCDIR}/common/SourceAppInfo.cpp
	snd_io.cpp
	EngineSoundServer.cpp
	$<$<BOOL:${LINUX}>:audio/private/snd_posix.cpp> # [$POSIX]
	audio/private/vox.cpp
	audio/private/voice_gain.cpp
	audio/private/voice_wavefile.cpp

	$<$<BOOL:${ENABLE_SDL}>:audio/private/snd_dev_sdl.cpp> # [$SDL && !$OSXALL]

	toolframework.cpp

	$<$<BOOL:${WINDOWS}>:${SRCDIR}/public/tier0/memoverride.cpp>
)

if(NOT DEDICATED)
	list(APPEND SOURCES
		client_pch.cpp  		# [!$DEDICATED]
		cl_rcon.cpp				# [!$DEDICATED]
		rpt_engine.cpp			# [!$DEDICATED]
		cl_steamauth.cpp		# [!$DEDICATED]
		r_efx.cpp				# [!$DEDICATED]
		view.cpp				# [!$DEDICATED]
		cdll_engine_int.cpp		# [!$DEDICATED]
		cl_main.cpp				# [!$DEDICATED]
		cl_demo.cpp				# [!$DEDICATED]
		cl_demoaction.cpp		# [!$DEDICATED]
		cl_demoaction_types.cpp	# [!$DEDICATED]
		cl_demoactioneditors.cpp	# [!$DEDICATED]
		cl_demoactionmanager.cpp	# [!$DEDICATED]
		cl_demoeditorpanel.cpp		# [!$DEDICATED]
		cl_demosmootherpanel.cpp	# [!$DEDICATED]
		cl_demouipanel.cpp			# [!$DEDICATED]
		cl_foguipanel.cpp			# [!$DEDICATED]
		cl_txviewpanel.cpp			# [!$DEDICATED]
		cl_entityreport.cpp			# [!$DEDICATED]
		cl_ents_parse.cpp			# [!$DEDICATED]
		cl_localnetworkbackdoor.cpp	# [!$DEDICATED]
		cl_parse_event.cpp			# [!$DEDICATED]
		cl_pluginhelpers.cpp		# [!$DEDICATED]
		cl_pred.cpp					# [!$DEDICATED]
		cl_texturelistpanel.cpp		# [!$DEDICATED]
		client.cpp					# [!$DEDICATED]
		colorcorrectionpanel.cpp	# [!$DEDICATED]
		buildcubemaps.cpp			# [!$DEDICATED]
		debug_leafvis.cpp			# [!$DEDICATED]
		debugoverlay.cpp			# [!$DEDICATED]
		gl_drawlights.cpp 			# [!$DEDICATED]
		gl_lightmap.cpp 			# [!$DEDICATED]
		gl_matsysiface.cpp  		# [!$DEDICATED]
		gl_rlight.cpp 				# [!$DEDICATED]
		gl_rmain.cpp 				# [!$DEDICATED]
		gl_rmisc.cpp 				# [!$DEDICATED]
		gl_screen.cpp 				# [!$DEDICATED]
		gl_warp.cpp 				# [!$DEDICATED]
		r_areaportal.cpp 			# [!$DEDICATED]
		shadowmgr.cpp 				# [!$DEDICATED]
		cl_bounded_cvars.cpp		# [!$DEDICATED]
		downloadthread.cpp			# [!$DEDICATED]
		LoadScreenUpdate.cpp		# [!$DEDICATED]
		matchmakinghost.cpp			# [!$DEDICATED]
		matchmakingqos.cpp			# [!$DEDICATED]
		matchmakingclient.cpp		# [!$DEDICATED]
		matchmakingshared.cpp		# [!$DEDICATED]
		matchmakingmigrate.cpp		# [!$DEDICATED]
		replaydemoplayer.cpp		# [!$DEDICATED]
		Session.cpp					# [!$DEDICATED]
		sys_mainwind.cpp			# [!$DEDICATED]
		bugreporter.cpp				# [!$DEDICATED]
		download.cpp				# [!$DEDICATED]
		host_saverestore.cpp		# [!$DEDICATED]
		lightcache.cpp				# [!$DEDICATED]
		saverestore_filesystem.cpp  # [!$DEDICATED]
		sys_getmodes.cpp			# [!$DEDICATED]
		vgui_askconnectpanel.cpp	# [!$DEDICATED]
		xboxsystem.cpp				# [!$DEDICATED]
		EngineSoundClient.cpp		# [!$DEDICATED]
		engsoundservice.cpp			# [!$DEDICATED]

		$<$<BOOL:${WINDOWS}>:audio/private/snd_dev_direct.cpp>	# [$WINDOWS]
		$<$<BOOL:${WINDOWS}>:audio/private/snd_dev_wave.cpp>	# [$WINDOWS]

		$<$<BOOL:${WINDOWS}>:audio/private/voice_mixer_controls.cpp>	# [$WINDOWS]
		$<$<BOOL:${WINDOWS}>:audio/private/voice_record_dsound.cpp>		# [$WINDOWS]
		audio/private/MPAFile.cpp	# [!$DEDICATED&&!$X360]
		audio/private/MPAHeader.cpp	# [!$DEDICATED&&!$X360]
		audio/private/circularbuffer.cpp	# [!$DEDICATED]
		audio/audio_pch.cpp					# [!$DEDICATED]
		audio/private/snd_dev_common.cpp	# [!$DEDICATED]
		audio/private/snd_dma.cpp			# [!$DEDICATED]
		audio/private/snd_dsp.cpp			# [!$DEDICATED]
		audio/private/snd_mix.cpp			# [!$DEDICATED]
		audio/private/snd_sentence_mixer.cpp	# [!$DEDICATED]
		audio/private/snd_wave_data.cpp			# [!$DEDICATED]
		audio/private/snd_wave_mixer.cpp		# [!$DEDICATED]
		audio/private/snd_wave_mixer_adpcm.cpp	# [!$DEDICATED]
		audio/private/snd_wave_source.cpp		# [!$DEDICATED]
		audio/private/snd_wave_temp.cpp 		# [!$DEDICATED]
		audio/private/snd_win.cpp 				# [!$DEDICATED]
		audio/private/snd_mp3_source.cpp		# [!$DEDICATED]
		audio/private/snd_wave_mixer_mp3.cpp	# [!$DEDICATED]
		audio/private/VBRHeader.cpp				# [!$DEDICATED&&!$X360]
		audio/private/voice.cpp					# [!$DEDICATED&&!$X360]
		audio/private/voice_sound_engine_interface.cpp	# [!$DEDICATED&&!$X360]

		$<$<BOOL:${LINUX}>:audio/private/voice_mixer_controls_openal.cpp>	# [$OSXALL||($LINUXALL&&!$DEDICATED)]
		$<$<BOOL:${LINUX}>:audio/private/voice_record_openal.cpp>			# [$OSXALL||($LINUXALL&&!$DEDICATED)]

		# VGUI Panels [!$DEDICATED]
		${SRCDIR}/public/vgui_controls/vgui_controls.cpp
		${SRCDIR}/common/vgui/vgui_basebudgetpanel.cpp
		${SRCDIR}/common/vgui/vgui_budgetbargraphpanel.cpp
		${SRCDIR}/common/vgui/vgui_budgethistorypanel.cpp
		${SRCDIR}/common/vgui/vgui_budgetpanelshared.cpp

		perfuipanel.cpp
		vgui_basepanel.cpp
		vgui_baseui_interface.cpp
		vgui_budgetpanel.cpp
		vgui_DebugSystemPanel.cpp
		vgui_drawtreepanel.cpp
		vgui_helpers.cpp
		vgui_texturebudgetpanel.cpp
		vgui_vprofgraphpanel.cpp
		vgui_vprofpanel.cpp
		# VGUI Panels [!$DEDICATED]
		enginetool.cpp		# [!$DEDICATED]
	)
endif()

add_library(${PROJECT} SHARED ${SOURCES})
target_compile_definitions(${PROJECT} PRIVATE
	USE_CONVARS VOICE_OVER_IP BUMPMAP
	__USEA3D _ADD_EAX_ ENGINE_DLL
	VERSION_SAFE_STEAM_API_INTERFACES
	USE_BREAKPAD_HANDLER
	$<$<BOOL:${LINUX}>:USE_WEBM_FOR_REPLAY>
)
target_include_directories(${PROJECT} PRIVATE
	${SRCDIR}/engine
	audio
	audio/public
	audio/private
	${SRCDIR}/public/engine/audio
)

if(LINUX)
	find_package(CURL REQUIRED)
endif()

if(NOT DEDICATED)
	find_package(OpenAL REQUIRED)
	find_package(JPEG REQUIRED)
	find_package(PNG REQUIRED)
endif()
#find_package(BZip2 REQUIRED)
find_package(ZLIB REQUIRED)

target_link_libraries(${PROJECT} PRIVATE
	appframework
	bitmap
	dmxloader
#	$<$<NOT:${DEDICATED}>:vgui_controls>
#	$<$<NOT:${DEDICATED}>:matsys_controls>
	tier0 tier1 tier2 tier3
	mathlib
	vstdlib
	vtf
	steam_api
#	$<$<NOT:${DEDICATED}>:JPEG::JPEG>
#	BZip2::BZip2
	ZLIB::ZLIB
#	$<$<AND:${LINUX},$<NOT:${DEDICATED}>>:${OPENAL_LIBRARY}>
	$<$<BOOL:${LINUX}>:CURL::libcurl>
	$<$<BOOL:${LINUX}>:rt>
	$<$<BOOL:${ENABLE_SDL}>:SDL2::SDL2>
	$<$<BOOL:${WINDOWS}>:dinput8.lib winmm.lib wsock32.lib ws2_32.lib wininet.lib vfw32.lib rpcrt4.lib>
)
install(TARGETS ${PROJECT} DESTINATION bin)