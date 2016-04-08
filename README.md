# CodecStepResponse

Description of codec configurations used to characterise codec step response

## x264

## openH264
```
  SEncParamExt param;
  m_pCodec->GetDefaultParams (&param);
  param.iUsageType = CAMERA_VIDEO_REAL_TIME;
  param.fMaxFrameRate = (uint32_t)m_in.getFps();
  param.iPicWidth = m_in.getWidth();
  param.iPicHeight = m_in.getHeight();
  param.iTargetBitrate = m_uiTargetBitrate * 1000;
  //param.bEnableDenoise = denoise;
  param.bEnableDenoise = false;
  param.iSpatialLayerNum = 1;
  //SM_DYN_SLICE don't support multi-thread now
#if 0
  if (sliceMode != SM_SINGLE_SLICE && sliceMode != SM_DYN_SLICE)
      param.iMultipleThreadIdc = 2;
#endif
  // RG: this prevents IDR generation on scene change
#if 1
  param.bEnableSceneChangeDetect = false;
#endif
  param.bEnableFrameSkip = false;
  for (int i = 0; i < param.iSpatialLayerNum; i++) {
      param.sSpatialLayers[i].iVideoWidth = m_in.getWidth() >> (param.iSpatialLayerNum - 1 - i);
      param.sSpatialLayers[i].iVideoHeight = m_in.getHeight() >> (param.iSpatialLayerNum - 1 - i);
      param.sSpatialLayers[i].fFrameRate = (uint32_t)m_in.getFps();
      param.sSpatialLayers[i].iSpatialBitrate = param.iTargetBitrate;
      param.sSpatialLayers[i].sSliceCfg.uiSliceMode = SM_SINGLE_SLICE;
#if 0
      param.sSpatialLayers[i].sSliceCfg.uiSliceMode = sliceMode;
      if (sliceMode == SM_DYN_SLICE) {
          param.sSpatialLayers[i].sSliceCfg.sSliceArgument.uiSliceSizeConstraint = 600;
          param.uiMaxNalSize = 1500;
      }
#endif
  }
  param.iTargetBitrate *= param.iSpatialLayerNum;
  m_pCodec->InitializeExt (&param);
  int videoFormat = videoFormatI420;
  m_pCodec->SetOption (ENCODER_OPTION_DATAFORMAT, &videoFormat);
```

## VPP-Cbr

## VPP-Pow

## VPP-Log


