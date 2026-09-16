
undefined8 *
owner_driver_C(undefined8 *param_1,long *param_2,long *param_3,long param_4,long *param_5,
              long *param_6,long *param_7,long param_8,long *param_9,long param_10,
              undefined8 param_11,char param_12)

{
  ushort *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  char cVar4;
  long lVar5;
  ulong *puVar6;
  int *piVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  ulong uVar11;
  ulong uVar12;
  long *extraout_RDX;
  int *piVar13;
  long lVar14;
  long lVar15;
  long *plVar16;
  long lVar17;
  undefined8 uVar18;
  int *piVar19;
  undefined1 uVar20;
  ulong uVar21;
  undefined1 uVar22;
  long *plVar23;
  ulong uVar24;
  long *plVar25;
  long *plVar26;
  undefined8 *puVar27;
  long *plVar28;
  undefined *puVar29;
  bool bVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [12];
  undefined1 auStack_1848 [168];
  long *plStack_17a0;
  long *plStack_1798;
  long *plStack_1790;
  long *plStack_1788;
  long *plStack_1780;
  long *plStack_1778;
  long *plStack_1770;
  long *plStack_1768;
  long *plStack_1760;
  long *plStack_1758;
  long *plStack_1750;
  long lStack_1748;
  undefined8 uStack_1740;
  int aiStack_1738 [4];
  undefined8 uStack_1728;
  undefined8 uStack_1710;
  long *plStack_16f8;
  long *plStack_16f0;
  long *plStack_16e8;
  long *plStack_16e0;
  long *plStack_16d8;
  long *plStack_16d0;
  long *plStack_16c8;
  long *plStack_16c0;
  long lStack_16b8;
  undefined4 uStack_16b0;
  long *plStack_16a8;
  undefined1 uStack_16a0;
  undefined7 uStack_169f;
  undefined1 uStack_1698;
  undefined7 uStack_1697;
  char cStack_1099;
  long *plStack_1098;
  long *plStack_1090;
  long *plStack_1088;
  long *plStack_1080;
  long *plStack_1078;
  long *plStack_1070;
  long *plStack_1068;
  undefined4 uStack_1060;
  undefined4 uStack_105c;
  undefined4 uStack_1058;
  undefined4 uStack_1054;
  undefined4 uStack_1050;
  undefined4 uStack_104c;
  undefined8 uStack_1030;
  long *plStack_f20;
  long *plStack_f18;
  long *plStack_f10;
  char cStack_9a9;
  long *plStack_9a8;
  long *plStack_9a0;
  long *plStack_998;
  undefined8 uStack_990;
  undefined8 uStack_978;
  undefined8 uStack_960;
  undefined8 uStack_948;
  undefined8 uStack_930;
  undefined1 uStack_918;
  long lStack_908;
  undefined8 uStack_900;
  undefined4 uStack_8f8;
  undefined4 uStack_8f4;
  undefined4 uStack_8f0;
  undefined4 uStack_8ec;
  long lStack_8e8;
  undefined8 uStack_8e0;
  undefined8 uStack_8d8;
  undefined8 uStack_8d0;
  long lStack_8c8;
  undefined8 uStack_8c0;
  undefined8 uStack_8b8;
  ulong uStack_8b0;
  long lStack_8a8;
  long *plStack_8a0;
  long *plStack_898;
  long *plStack_888;
  long *plStack_880;
  long *plStack_878;
  long *plStack_868;
  long *plStack_860;
  undefined4 uStack_858;
  undefined4 uStack_854;
  undefined4 uStack_850;
  undefined4 uStack_84c;
  undefined4 uStack_848;
  undefined4 uStack_844;
  undefined4 uStack_840;
  undefined4 uStack_83c;
  long *plStack_838;
  long *plStack_830;
  long *plStack_828;
  undefined8 uStack_820;
  long *plStack_818;
  long *plStack_810;
  long *plStack_808;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 uStack_7f8;
  undefined4 uStack_7f4;
  long *plStack_7f0;
  long *plStack_7e8;
  undefined8 uStack_7e0;
  undefined8 uStack_7d8;
  undefined8 uStack_7d0;
  undefined8 uStack_7c8;
  undefined8 uStack_7c0;
  char cStack_750;
  char cStack_74f;
  char cStack_74e;
  char cStack_74d;
  char cStack_74c;
  char cStack_74a;
  char cStack_73f;
  char cStack_73b;
  long lStack_738;
  undefined8 uStack_730;
  long lStack_718;
  undefined8 uStack_710;
  long lStack_6f8;
  undefined8 uStack_6f0;
  long *plStack_6d8;
  long *plStack_6d0;
  undefined8 uStack_6c8;
  undefined8 uStack_6c0;
  undefined8 uStack_6b8;
  undefined8 uStack_6b0;
  undefined8 uStack_6a8;
  undefined8 uStack_6a0;
  long lStack_698;
  undefined8 uStack_690;
  long *plStack_5e8;
  long *plStack_5e0;
  long *plStack_5d8;
  long *plStack_5d0;
  long *plStack_5c8;
  long *plStack_5c0;
  long *plStack_5b8;
  long *plStack_5b0;
  long lStack_5a8;
  long *plStack_5a0;
  long *plStack_598;
  undefined4 uStack_590;
  undefined4 uStack_58c;
  undefined4 uStack_588;
  undefined4 uStack_584;
  undefined4 uStack_580;
  undefined4 uStack_57c;
  undefined4 uStack_578;
  undefined4 uStack_574;
  undefined4 uStack_570;
  undefined4 uStack_56c;
  undefined4 uStack_568;
  undefined4 uStack_564;
  long lStack_560;
  undefined8 uStack_558;
  long **pplStack_550;
  long **pplStack_548;
  long *plStack_540;
  long **pplStack_538;
  long lStack_530;
  long lStack_528;
  long *plStack_518;
  long *plStack_510;
  long *plStack_508;
  long *plStack_500;
  long *plStack_4f8;
  long *plStack_4f0;
  long *plStack_4e8;
  long lStack_4e0;
  long *plStack_4d8;
  long *plStack_4d0;
  long *plStack_4c0;
  long *plStack_4b8;
  long *plStack_4b0;
  long *plStack_4a8;
  long *plStack_4a0;
  undefined8 uStack_498;
  undefined8 uStack_490;
  long *plStack_488;
  long *plStack_480;
  long *plStack_478;
  long *plStack_470;
  long *plStack_468;
  long *plStack_458;
  long *plStack_450;
  undefined8 uStack_448;
  undefined8 uStack_440;
  undefined8 uStack_438;
  undefined8 uStack_430;
  long *plStack_428;
  long *plStack_420;
  long *plStack_418;
  long *plStack_408;
  long *plStack_400;
  undefined8 uStack_3f8;
  int iStack_3f0;
  int iStack_3ec;
  int iStack_3e8;
  int iStack_3e4;
  int iStack_3e0;
  int iStack_3dc;
  int iStack_3d8;
  int iStack_3d4;
  int iStack_3d0;
  int iStack_3cc;
  long lStack_3c8;
  long lStack_3c0;
  undefined8 uStack_3b8;
  long lStack_3a8;
  undefined8 uStack_3a0;
  long lStack_390;
  undefined8 uStack_388;
  long *plStack_368;
  long *plStack_360;
  long *plStack_358;
  long *plStack_350;
  long *plStack_348;
  long *plStack_340;
  long *plStack_338;
  long *plStack_330;
  long lStack_328;
  long *plStack_320;
  long *plStack_318;
  long lStack_310;
  long *plStack_308;
  long *plStack_268;
  long *plStack_260;
  long lStack_258;
  long *plStack_250;
  long *plStack_248;
  long *plStack_240;
  long *plStack_238;
  long *plStack_230;
  long *plStack_228;
  long *plStack_220;
  long *plStack_218;
  undefined8 uStack_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 *puStack_1f0;
  long *plStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_198;
  undefined1 uStack_160;
  undefined4 uStack_15f;
  undefined2 uStack_15b;
  undefined1 uStack_14f;
  char cStack_14c;
  undefined1 uStack_14b;
  long lStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  ulong uStack_130;
  long lStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  long lStack_108;
  undefined8 uStack_100;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  long *plStack_e8;
  long *plStack_e0;
  long *plStack_d8;
  long lStack_d0;
  long lStack_c8;
  long lStack_c0;
  long lStack_b8;
  undefined8 *puStack_b0;
  long *plStack_a8;
  undefined8 uStack_a0;
  long *plStack_98;
  long *plStack_90;
  long *plStack_88;
  long *plStack_80;
  long lStack_70;
  long *plStack_68;
  long *plStack_60;
  long *plStack_58;
  undefined1 uStack_49;
  long lStack_48;
  long *plStack_40;
  long *plStack_38;
  
  uStack_1030 = 0;
  plStack_a8 = param_5;
  plStack_98 = param_6;
  plStack_88 = param_3;
  lStack_48 = param_4;
  func_0x07588770(&lStack_d0,param_7);
  owner_child_control(&plStack_4c0,param_7);
  func_0x075888a0(&lStack_d0);
  if (lStack_c0 != 0) {
    func_0x075875b0(&lStack_d0);
  }
  func_0x06930700(&plStack_1098,param_2);
  plStack_1788 = plStack_1090;
  plStack_1780 = plStack_1088;
  plStack_1778 = plStack_1080;
  puStack_b0 = param_1;
  if (plStack_1098 != (long *)0xffffffffffffffff) {
    uStack_440 = CONCAT44(uStack_105c,uStack_1060);
    uStack_438 = (long *)CONCAT44(uStack_1054,uStack_1058);
    uStack_430 = (long *)CONCAT44(uStack_104c,uStack_1050);
    uStack_448 = plStack_1068;
    plStack_458 = plStack_1078;
    plStack_450 = plStack_1070;
    plStack_e8 = plStack_1090;
    plStack_e0 = plStack_1088;
    plStack_d8 = plStack_1080;
    plVar16 = plStack_4b8;
    plVar28 = plStack_1098;
    if (plStack_4b0 == (long *)0x0) goto code_r0x071d90ad;
    goto code_r0x071d81e2;
  }
  plStack_478 = plStack_1090;
  plStack_470 = plStack_1088;
  plStack_468 = plStack_1080;
  lStack_b8 = *param_7;
  if (lStack_b8 == 2) {
code_r0x071d8317:
    plStack_368 = (long *)0x2;
  }
  else {
    plVar28 = (long *)param_7[0x94];
    plVar16 = (long *)param_7[0x95];
    plStack_58 = param_2;
    if (*(char *)((long)param_7 + 0x734) == '\x01') {
      plVar23 = (long *)(*(code *)&DAT_06c60840)(plVar28,plVar16);
      if (plVar23 == (long *)0x0) goto code_r0x071da78e;
      if (*plVar23 != -1) {
        plVar16 = (long *)0xc;
      }
      if ((int)*plVar23 != -1) {
        plVar28 = (long *)&UNK_006de48d;
      }
    }
    lVar15 = (*(code *)&DAT_06c60840)(plVar28,plVar16);
    if (lVar15 == 0) goto code_r0x071da78e;
    lVar5 = *(long *)(lVar15 + 0xb8);
    param_2 = plStack_58;
    if (lVar5 == 0) goto code_r0x071d8317;
    param_5 = *(long **)(lVar15 + 0xe0);
    uVar9 = *(undefined8 *)(lVar15 + 0xd8);
    uVar18 = *(undefined8 *)(lVar15 + 0xd0);
    param_1 = *(undefined8 **)(lVar15 + 200);
    func_0x07c27450(&plStack_1098,lVar5,*(long *)(lVar15 + 0xc0) * 0x10 + lVar5);
    param_2 = plStack_58;
    func_0x0763da10(&plStack_368,param_1,uVar18,uVar9,param_5,&plStack_1098);
  }
  func_0x072a56d0(&plStack_1098,param_2);
  lVar15 = lStack_48;
  auVar31 = (**(code **)(lStack_48 + 0x128))(plStack_88);
  auVar32._8_8_ = plStack_338;
  auVar32._0_8_ = plStack_340;
  plVar28 = auVar31._8_8_;
  if (auVar31._0_8_ == 0) {
    plVar16 = (long *)0xffffffffffffffff;
    if ((int)plStack_368 == 2) goto code_r0x071d8391;
    if (plStack_348 != (long *)0xffffffffffffffff) {
      auVar31 = auVar32;
      plVar28 = plStack_338;
      if ((long)plStack_338 < 0) {
        plVar28 = (long *)0x0;
        plVar16 = plStack_338;
        goto code_r0x071d8385;
      }
      goto joined_r0x071d83a6;
    }
code_r0x071d83e9:
    auVar31 = (**(code **)(lVar15 + 0x130))(plStack_88);
  }
  else {
    if ((long)plVar28 < 0) goto code_r0x071d83fe;
joined_r0x071d83a6:
    if (plVar28 != (long *)0x0) {
      plVar16 = auVar31._8_8_;
      plStack_40 = auVar31._0_8_;
      (*(code *)&DAT_04732870)();
      plVar28 = (long *)0x1;
      plVar23 = (long *)(*(code *)&DAT_04732830)(plVar16,1);
      if (plVar23 == (long *)0x0) goto code_r0x071d8385;
      plStack_38 = plVar23;
      (*(code *)&DAT_120cba68)(plVar23,plStack_40,plVar16);
      goto code_r0x071d83e9;
    }
    plStack_38 = (long *)0x1;
    plVar16 = (long *)0x0;
    auVar31 = (**(code **)(lVar15 + 0x130))(plStack_88);
  }
  if (auVar31._0_8_ == 0) goto code_r0x071d843e;
code_r0x071d83f9:
  plVar28 = auVar31._8_8_;
  if ((long)plVar28 < 0) {
code_r0x071d83fe:
    plVar16 = (long *)0x0;
    auVar31 = (*(code *)&DAT_1208422d)(0,plVar28);
  }
  plVar28 = auVar31._8_8_;
  do {
    if (plVar28 == (long *)0x0) {
      lStack_70 = 1;
      plStack_90 = (long *)0x0;
      goto code_r0x071d84ce;
    }
    plVar23 = auVar31._8_8_;
    plStack_58 = auVar31._0_8_;
    plStack_40 = plVar16;
    (*(code *)&DAT_04732870)();
    plVar28 = (long *)0x1;
    lVar5 = (*(code *)&DAT_04732830)(plVar23,1);
    plVar16 = plVar23;
    if (lVar5 != 0) {
      lStack_70 = lVar5;
      (*(code *)&DAT_120cba68)(lVar5,plStack_58,plVar23);
      plStack_90 = plVar23;
      plVar16 = plStack_40;
      goto code_r0x071d84ce;
    }
code_r0x071d8385:
    (*(code *)&DAT_1208422d)(plVar28,plVar16);
    plVar16 = plVar28;
code_r0x071d8391:
    auVar31 = (**(code **)(lVar15 + 0x130))(plStack_88);
    if (auVar31._0_8_ != 0) goto code_r0x071d83f9;
code_r0x071d843e:
    plVar28 = plStack_320;
    auVar31._8_8_ = plStack_320;
    auVar31._0_8_ = lStack_328;
    plStack_90 = (long *)0xffffffffffffffff;
    if (((int)plStack_368 == 2) || (plStack_330 == (long *)0xffffffffffffffff))
    goto code_r0x071d84ce;
  } while (-1 < (long)plStack_320);
  plVar16 = (long *)0x0;
  (*(code *)&DAT_1208422d)(0,plStack_320);
  plStack_90 = plVar28;
code_r0x071d84ce:
  plStack_40 = plVar16;
  auVar32 = (**(code **)(lVar15 + 0x138))(plStack_88);
  plStack_220 = plStack_38;
  plVar28 = auVar32._8_8_;
  uVar22 = SUB81(param_5,0);
  if (auVar32._0_8_ == 0) {
    plStack_68 = (long *)0xffffffffffffffff;
    if (((int)plStack_368 == 2) || (plStack_318 == (long *)0xffffffffffffffff))
    goto code_r0x071d86cd;
    lVar5 = (long)plStack_308 * 0x18;
    if ((long *)0x555555555555555 < plStack_308) goto code_r0x071d85eb;
    if (lVar5 == 0) {
      param_1 = (undefined8 *)0x8;
      plStack_68 = (long *)0x0;
      lVar15 = lStack_48;
      goto code_r0x071d86cd;
    }
    plStack_68 = plStack_308;
    (*(code *)&DAT_04732870)();
    param_1 = (undefined8 *)(*(code *)&DAT_04732830)(lVar5,8);
    uVar22 = SUB81(param_5,0);
    uVar9 = 8;
    if (param_1 != (undefined8 *)0x0) {
      if (plStack_68 != (long *)0x0) {
        lVar14 = 0;
        plVar28 = plStack_68;
        plStack_58 = param_2;
        goto code_r0x071d865e;
      }
code_r0x071d86a9:
      plStack_68 = (long *)0x0;
      lVar15 = lStack_48;
      goto code_r0x071d86cd;
    }
  }
  else {
    lVar5 = (long)plVar28 * 0x18;
    if (plVar28 < (long *)0x555555555555556) {
      if (lVar5 == 0) goto code_r0x071d85f6;
      plStack_68 = plVar28;
      (*(code *)&DAT_04732870)();
      param_1 = (undefined8 *)(*(code *)&DAT_04732830)(lVar5,8);
      uVar22 = SUB81(param_5,0);
      uVar9 = 8;
      if (param_1 != (undefined8 *)0x0) {
        plStack_220 = plStack_38;
        if (plStack_68 != (long *)0x0) {
          lVar14 = 0;
          plVar28 = plStack_68;
          plStack_58 = param_2;
          goto code_r0x071d8560;
        }
        goto code_r0x071d86a9;
      }
    }
    else {
code_r0x071d85eb:
      uVar9 = 0;
    }
  }
  (*(code *)&DAT_1208422d)(uVar9,lVar5);
code_r0x071d85f6:
  param_1 = (undefined8 *)0x8;
  plStack_68 = (long *)0x0;
  plStack_220 = plStack_38;
  lVar15 = lStack_48;
  goto code_r0x071d86cd;
  while( true ) {
    (*(code *)&DAT_120846f0)(&plStack_248,lStack_310 + lVar14);
    uVar22 = SUB81(param_5,0);
    *(long **)((long)param_1 + lVar14 + 0x10) = plStack_238;
    *(undefined8 *)((long)param_1 + lVar14) = plStack_248;
    ((undefined8 *)((long)param_1 + lVar14))[1] = plStack_240;
    lVar14 = lVar14 + 0x18;
    plVar28 = (long *)((long)plVar28 + -1);
    plStack_220 = plStack_38;
    lVar15 = lStack_48;
    param_2 = plStack_58;
    if (plVar28 == (long *)0x0) break;
code_r0x071d865e:
    uVar22 = SUB81(param_5,0);
    plStack_220 = plStack_38;
    lVar15 = lStack_48;
    param_2 = plStack_58;
    if (lVar5 == lVar14) break;
  }
  goto code_r0x071d86cd;
  while( true ) {
    (*(code *)&DAT_120846f0)(&plStack_248,auVar32._0_8_ + lVar14);
    uVar22 = SUB81(param_5,0);
    *(long **)((long)param_1 + lVar14 + 0x10) = plStack_238;
    *(undefined8 *)((long)param_1 + lVar14) = plStack_248;
    ((undefined8 *)((long)param_1 + lVar14))[1] = plStack_240;
    lVar14 = lVar14 + 0x18;
    plVar28 = (long *)((long)plVar28 + -1);
    plStack_220 = plStack_38;
    lVar15 = lStack_48;
    param_2 = plStack_58;
    if (plVar28 == (long *)0x0) break;
code_r0x071d8560:
    uVar22 = SUB81(param_5,0);
    plStack_220 = plStack_38;
    lVar15 = lStack_48;
    param_2 = plStack_58;
    if (lVar5 == lVar14) break;
  }
code_r0x071d86cd:
  uStack_210 = plStack_90;
  uStack_208 = lStack_70;
  uStack_200 = plStack_90;
  uStack_1f8 = plStack_68;
  plStack_1e8 = plStack_68;
  uStack_160 = 2;
  uStack_15f = 0x2020202;
  uStack_15b = 0xff02;
  plStack_248 = (long *)0x0;
  uStack_198 = 0xfffffffffffffffe;
  uStack_1e0 = 0xffffffffffffffff;
  plStack_228 = plStack_40;
  plStack_218 = plStack_40;
  puStack_1f0 = param_1;
  (*(code *)&DAT_0afa5ac0)(&plStack_248);
  (*(code *)&DAT_120cba68)(&plStack_838,&plStack_248,0xf0);
  cVar4 = (**(code **)(lVar15 + 0x140))(plStack_88);
  if (cVar4 != '\x02') {
    cStack_750 = cVar4;
  }
  cVar4 = (**(code **)(lVar15 + 0x148))(plStack_88);
  if (cVar4 != -1) {
    cStack_74a = cVar4;
  }
  cVar4 = (**(code **)(lVar15 + 0x150))(plStack_88);
  if (cVar4 != '\x02') {
    cStack_74f = cVar4;
  }
  cVar4 = (**(code **)(lVar15 + 0x158))(plStack_88);
  if (cVar4 != '\x02') {
    cStack_74e = cVar4;
  }
  plStack_58 = param_2;
  cVar4 = (**(code **)(lVar15 + 0x160))(plStack_88);
  if (cVar4 != '\x02') {
    cStack_74d = cVar4;
  }
  plVar28 = (long *)(**(code **)(lVar15 + 0x168))(plStack_88);
  if (plVar28 != (long *)0x0) {
    uVar10 = (undefined1)plVar28[6];
    if (*plVar28 == -1) {
      plStack_6d8 = (long *)0xffffffffffffffff;
      goto code_r0x071d890c;
    }
    plVar16 = (long *)plVar28[2];
    plVar23 = (long *)((long)plVar16 * 0x18);
    if (plVar16 < (long *)0x555555555555556) {
      if (plVar23 != (long *)0x0) {
        plStack_68 = (long *)CONCAT71(plStack_68._1_7_,uVar10);
        lVar15 = plVar28[1];
        plStack_38 = plVar16;
        (*(code *)&DAT_04732870)();
        uVar20 = 8;
        plStack_40 = (long *)(*(code *)&DAT_04732830)(plVar23);
        plStack_6d8 = plVar23;
        if (plStack_40 != (long *)0x0) {
          if (plStack_38 == (long *)0x0) {
            plStack_6d8 = (long *)0x0;
            uVar10 = SUB81(plStack_68,0);
            lVar15 = lStack_48;
          }
          else {
            plVar26 = (long *)0x0;
            plVar16 = plStack_38;
            do {
              if (plVar23 == plVar26) break;
              (*(code *)&DAT_120846f0)(&plStack_248,(undefined *)(lVar15 + (long)plVar26));
              *(long **)((long)(plStack_40 + 2) + (long)plVar26) = plStack_238;
              *(undefined8 *)((long)plStack_40 + (long)plVar26) = plStack_248;
              ((undefined8 *)((long)plStack_40 + (long)plVar26))[1] = plStack_240;
              plVar26 = plVar26 + 3;
              plVar16 = (long *)((long)plVar16 + -1);
            } while (plVar16 != (long *)0x0);
            uVar10 = SUB81(plStack_68,0);
            plStack_6d8 = plStack_38;
            lVar15 = lStack_48;
          }
          goto code_r0x071d890c;
        }
        goto code_r0x071d8935;
      }
      plStack_40 = (long *)0x8;
      plStack_6d8 = (long *)0x0;
code_r0x071d890c:
      uStack_6c0 = (long *)0xffffffffffffffff;
      uVar20 = *(undefined *)((long)plVar28 + 0x31);
      uVar22 = *(undefined *)((long)plVar28 + 0x32);
      if (plVar28[3] != -1) {
        plVar16 = (long *)plVar28[5];
        plVar23 = (long *)((long)plVar16 * 0x18);
        if ((long *)0x555555555555555 < plVar16) goto code_r0x071d8932;
        if (plVar23 == (long *)0x0) {
          plVar28 = (long *)0x8;
          uStack_6c0 = (long *)0x0;
        }
        else {
          uStack_a0 = CONCAT71(uStack_a0._1_7_,uVar22);
          lStack_70 = CONCAT71(lStack_70._1_7_,uVar20);
          plStack_68 = (long *)CONCAT71(plStack_68._1_7_,uVar10);
          lVar15 = plVar28[4];
          plStack_90 = plVar16;
          plStack_38 = plStack_6d8;
          (*(code *)&DAT_04732870)();
          uVar20 = 8;
          plVar16 = (long *)(*(code *)&DAT_04732830)(plVar23,8);
          plStack_6d8 = plVar23;
          if (plVar16 == (long *)0x0) goto code_r0x071d8935;
          if (plStack_90 == (long *)0x0) {
            uStack_6c0 = (long *)0x0;
          }
          else {
            plVar26 = (long *)0x0;
            plVar28 = plStack_90;
            do {
              if (plVar23 == plVar26) break;
              (*(code *)&DAT_120846f0)(&plStack_248,(undefined *)(lVar15 + (long)plVar26));
              *(long **)((long)(plVar16 + 2) + (long)plVar26) = plStack_238;
              *(undefined8 *)((long)plVar16 + (long)plVar26) = plStack_248;
              ((undefined8 *)((long)plVar16 + (long)plVar26))[1] = plStack_240;
              plVar26 = plVar26 + 3;
              plVar28 = (long *)((long)plVar28 + -1);
            } while (plVar28 != (long *)0x0);
            uStack_6c0 = plStack_90;
          }
          plStack_6d8 = plStack_38;
          lVar15 = lStack_48;
          plVar28 = plVar16;
          uVar20 = (undefined1)lStack_70;
          uVar22 = (undefined1)uStack_a0;
          uVar10 = plStack_68._0_1_;
        }
      }
    }
    else {
code_r0x071d8932:
      uVar20 = 0;
      plStack_6d8 = plVar23;
code_r0x071d8935:
      (*(code *)&DAT_1208422d)();
      uStack_6c0 = extraout_RDX;
    }
    plVar16 = uStack_6a8;
    plStack_6d0 = plStack_40;
    uStack_6a8._3_5_ = SUB85(plVar16,3);
    uStack_6a8._0_3_ = CONCAT12(uVar22,CONCAT11(uVar20,uVar10));
    uStack_6c8 = plStack_6d8;
    uStack_6b8 = plVar28;
    uStack_6b0 = uStack_6c0;
    (*(code *)&DAT_120cba68)(&plStack_248,&plStack_838,0xf0);
    (*(code *)&DAT_0afa5300)(&plStack_838,&plStack_248,&plStack_6d8);
  }
  cVar4 = (**(code **)(lVar15 + 0x170))(plStack_88);
  if (cVar4 != '\x02') {
    cStack_74c = cVar4;
  }
  puVar6 = (ulong *)(**(code **)(lVar15 + 0x178))();
  if (((puVar6 != (ulong *)0x0) && (uVar11 = *puVar6, uVar11 != 0)) &&
     (plVar28 = (long *)puVar6[2], plVar28 != (long *)0x0)) {
    uVar12 = 0;
    plVar16 = (long *)puVar6[1];
    do {
      if (uVar12 == 0) {
        uVar24 = uVar11;
        if (plVar16 != (long *)0x0) {
          plVar23 = plVar16;
          if (((ulong)plVar16 & 7) != 0) {
            uVar12 = 0;
            do {
              uVar11 = *(ulong *)(uVar11 + 0x328);
              uVar12 = uVar12 + 1;
            } while (((ulong)plVar16 & 7) != uVar12);
            plVar23 = (long *)((long)plVar16 - uVar12);
          }
          uVar24 = uVar11;
          if ((long *)0x7 < plVar16) {
            do {
              uVar11 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long
                                                                                                *)(
                                                  uVar11 + 0x328) + 0x328) + 0x328) + 0x328) + 0x328
                                                  ) + 0x328) + 0x328) + 0x328);
              plVar23 = plVar23 + -1;
              uVar24 = uVar11;
            } while (plVar23 != (long *)0x0);
          }
        }
        plVar16 = (long *)0x0;
        uVar11 = 0;
        if (*(short *)(uVar24 + 0x322) == 0) goto code_r0x071d8c40;
      }
      else {
        uVar24 = uVar12;
        if ((long *)(ulong)*(ushort *)(uVar12 + 0x322) <= plVar16) {
code_r0x071d8c40:
          do {
            uVar12 = *(ulong *)(uVar24 + 0x210);
            if (uVar12 == 0) {
              (*(code *)&DAT_120a4420)(&UNK_1213d1a8);
              goto code_r0x071da83e;
            }
            uVar11 = uVar11 + 1;
            puVar1 = (ushort *)(uVar24 + 800);
            plVar16 = (long *)(ulong)*puVar1;
            uVar24 = uVar12;
          } while (*(ushort *)(uVar12 + 0x322) <= *puVar1);
        }
      }
      uVar12 = uVar24;
      if (uVar11 == 0) {
        plStack_38 = (long *)((long)plVar16 + 1);
      }
      else {
        puVar6 = (ulong *)(uVar24 + 0x330 + (long)plVar16 * 8);
        uVar21 = uVar11;
        if ((uVar11 & 7) != 0) {
          uVar21 = 0;
          do {
            uVar12 = *puVar6;
            puVar6 = (ulong *)(uVar12 + 0x328);
            uVar21 = uVar21 + 1;
          } while ((uVar11 & 7) != uVar21);
          uVar21 = uVar11 - uVar21;
        }
        if (7 < uVar11) {
          do {
            uVar12 = *(ulong *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*puVar6 
                                                  + 0x328) + 0x328) + 0x328) + 0x328) + 0x328) +
                                         0x328) + 0x328);
            puVar6 = (ulong *)(uVar12 + 0x328);
            uVar21 = uVar21 - 8;
          } while (uVar21 != 0);
        }
        plStack_38 = (long *)0x0;
      }
      lVar15 = (long)plVar16 * 0x30;
      plStack_40 = plVar28;
      (*(code *)&DAT_120cba68)(&plStack_248,&plStack_838,0xf0);
      uVar22 = *(undefined1 *)(uVar24 + 0x28 + lVar15);
      plVar28 = *(long **)(uVar24 + lVar15);
      plVar23 = (long *)((undefined8 *)(uVar24 + lVar15))[1];
      if (*(long *)(uVar24 + 0x10 + lVar15) == -1) {
        uStack_6c8 = (long *)0xffffffffffffffff;
        plStack_6d8 = plVar28;
        plStack_6d0 = plVar23;
      }
      else {
        plStack_68 = plVar28;
        plStack_60 = plVar23;
        (*(code *)&DAT_120846f0)(&plStack_5e8,uVar24 + 0x10 + lVar15);
        plStack_408 = plStack_5e0;
        plStack_400 = plStack_5d8;
        uStack_6c8 = plStack_5e8;
        plStack_6d8 = plStack_68;
        plStack_6d0 = plStack_60;
      }
      plVar28 = (long *)((long)plStack_40 + -1);
      uStack_6b0 = (long *)CONCAT71(uStack_6b0._1_7_,uVar22);
      uStack_6c0 = plStack_408;
      uStack_6b8 = plStack_400;
      func_0x0763d5a0(&plStack_838,&plStack_248,uVar24 + 0x218 + (long)plVar16 * 0x18,&plStack_6d8);
      uVar11 = 0;
      plVar16 = plStack_38;
    } while (plVar28 != (long *)0x0);
  }
  lVar15 = (**(code **)(lStack_48 + 0x180))(plStack_88);
  if (lVar15 != 0) {
    if (*(long *)(lVar15 + 0x18) == -1) {
      plVar28 = (long *)0xffffffffffffffff;
    }
    else {
      (*(code *)&DAT_120846f0)(&plStack_248,lVar15 + 0x18);
      plStack_5e8 = plStack_240;
      plStack_5e0 = plStack_238;
      plVar28 = plStack_248;
    }
    uVar22 = *(undefined1 *)(lVar15 + 0x40);
    plStack_88 = *(long **)(lVar15 + 0x30);
    plStack_80 = *(long **)(lVar15 + 0x38);
    func_0x07c42860(&plStack_6d8,lVar15);
    uStack_6b8 = plStack_5e8;
    uStack_6b0 = plStack_5e0;
    uStack_6a8 = plStack_88;
    uStack_6a0 = plStack_80;
    lStack_698 = CONCAT71(lStack_698._1_7_,uVar22);
    uStack_6c0 = plVar28;
    (*(code *)&DAT_120cba68)(&plStack_248,&plStack_838,0xf0);
    (*(code *)&DAT_0afa5230)(&plStack_838,&plStack_248,&plStack_6d8);
  }
  (*(code *)&DAT_0af0cdb0)(&plStack_1098,&plStack_838);
  (*(code *)&DAT_120cba68)(&plStack_1788,&plStack_1098,0x6f0);
  if ((int)plStack_368 != 2) {
    func_0x06fc3430(&plStack_368);
  }
  lVar5 = lStack_c8;
  plStack_9a8 = (long *)0xffffffffffffffff;
  uStack_990 = 0xffffffffffffffff;
  uStack_978 = 0xffffffffffffffff;
  uStack_960 = 0xffffffffffffffff;
  uStack_948 = 0xffffffffffffffff;
  uStack_930 = 0xffffffffffffffff;
  uStack_918 = 2;
  lVar15 = lStack_c8 + lStack_c0 * 0x18;
  lStack_258 = param_8;
  plStack_250 = param_9;
  plStack_268 = plStack_a8;
  plStack_260 = plStack_98;
  auVar33 = (*(code *)&DAT_12035950)();
  lStack_48 = auVar33._0_8_;
  plStack_88 = (long *)CONCAT44(plStack_88._4_4_,auVar33._8_4_);
  (*(code *)&DAT_0af0c080)(&plStack_9a8);
  (*(code *)&DAT_120cba68)(&plStack_5e8,&plStack_9a8,0x98);
  pplStack_548 = &plStack_478;
  plStack_540 = &lStack_258;
  pplStack_538 = &plStack_268;
  lStack_530 = lVar5;
  pplStack_550 = &plStack_1788;
  lStack_528 = lVar15;
  (*(code *)&DAT_0af0c050)(&plStack_1098,&plStack_5e8);
  if ((int)plStack_1098 != -1) {
code_r0x071d8fa6:
    uStack_200 = (long *)CONCAT44(uStack_1054,uStack_1058);
    uStack_1f8 = (long *)CONCAT44(uStack_104c,uStack_1050);
    uStack_210 = plStack_1068;
    uStack_208 = CONCAT44(uStack_105c,uStack_1060);
    plStack_220 = plStack_1078;
    plStack_218 = plStack_1070;
    plStack_230 = plStack_1088;
    plStack_228 = plStack_1080;
    plStack_240 = plStack_1098;
    plStack_238 = plStack_1090;
    plStack_248 = (long *)0xffffffffffffffff;
    func_0x06fbcfb0(&plStack_5e8);
    lVar15 = lStack_48;
    uVar3 = plStack_88._0_4_;
    goto code_r0x071d900c;
  }
  (*(code *)&DAT_0af0d490)(&plStack_1098,&plStack_1788);
  plVar23 = plStack_250;
  lVar14 = lStack_258;
  if ((int)plStack_1098 != -1) goto code_r0x071d8fa6;
  (*(code *)&DAT_120cba68)(&plStack_408,&plStack_5e8,0x98);
  plStack_98 = plStack_268;
  plStack_a8 = plStack_260;
  if (lVar14 == 0) {
    piVar7 = (int *)0x0;
  }
  else {
    (*(code *)&DAT_0af1c580)(&plStack_1098,lVar14,plVar23);
    if (plStack_1098 != (long *)0xffffffffffffffff) {
      lStack_8a8 = CONCAT44(uStack_105c,uStack_1060);
      plStack_8a0 = (long *)CONCAT44(uStack_1054,uStack_1058);
      plStack_898 = (long *)CONCAT44(uStack_104c,uStack_1050);
      uStack_210 = plStack_1068;
      plStack_240 = plStack_1098;
      plStack_238 = plStack_1090;
      plStack_218 = plStack_1070;
      plStack_230 = plStack_1088;
      plStack_228 = plStack_1080;
      plStack_220 = plStack_1078;
      goto code_r0x071d91d3;
    }
    piVar7 = (int *)(*(code *)&DAT_0af11a90)(&plStack_478,lVar14,plVar23);
    if (piVar7 == (int *)0x0) {
      func_0x064d5bf0(&plStack_1098,plVar23,0,1,1);
      plVar28 = plStack_1088;
      if ((int)plStack_1098 != 1) {
        plVar16 = (long *)0x2b;
        plVar25 = (long *)0x8;
        plVar26 = plStack_1090;
        if (plVar23 == (long *)0x0) goto code_r0x071da7a7;
        plStack_98 = plStack_1090;
        (*(code *)&DAT_120cba68)(plStack_1088,lVar14,plVar23);
        plVar26 = plStack_98;
        goto code_r0x071da7ab;
      }
code_r0x071da84e:
      (*(code *)&DAT_1208422d)();
code_r0x071da85b:
      (*(code *)&DAT_1208422d)(1,9);
code_r0x071da86b:
      (*(code *)&DAT_1208422d)(1,0xd);
      pcVar2 = (code *)swi(3);
      puVar27 = (undefined8 *)(*pcVar2)();
      return puVar27;
    }
  }
  plVar28 = (long *)0x0;
  plVar16 = plStack_400;
  if (plStack_408 == (long *)0xffffffffffffffff) {
    plVar16 = plVar28;
  }
  plStack_40 = plStack_408;
  plStack_90 = plStack_400;
  if (piVar7 != (int *)0x0) {
    if (*(long *)(piVar7 + 0x3c) == -1) {
      plVar28 = (long *)0x0;
    }
    else {
      plVar28 = *(long **)(piVar7 + 0x3e);
    }
  }
  lVar14 = 0;
  (*(code *)&DAT_0af1c4d0)(&lStack_8c8,plVar16,uStack_3f8,plVar28);
  plStack_38 = (long *)CONCAT44(iStack_3ec,iStack_3f0);
  lStack_70 = CONCAT44(iStack_3e4,iStack_3e8);
  lVar17 = lStack_70;
  if (plStack_38 == (long *)0xffffffffffffffff) {
    lVar17 = lVar14;
  }
  if (piVar7 != (int *)0x0) {
    if (*(long *)(piVar7 + 0x42) == -1) {
      lVar14 = 0;
    }
    else {
      lVar14 = *(long *)(piVar7 + 0x44);
    }
  }
  uVar9 = 0;
  (*(code *)&DAT_0af1c4d0)(&lStack_8e8,lVar17,CONCAT44(iStack_3dc,iStack_3e0),lVar14);
  plStack_68 = (long *)CONCAT44(iStack_3d4,iStack_3d8);
  uStack_a0 = CONCAT44(iStack_3cc,iStack_3d0);
  uVar18 = uStack_a0;
  if (plStack_68 == (long *)0xffffffffffffffff) {
    uVar18 = uVar9;
  }
  if (piVar7 != (int *)0x0) {
    if (*(long *)(piVar7 + 0x48) == -1) {
      uVar9 = 0;
    }
    else {
      uVar9 = *(undefined8 *)(piVar7 + 0x4a);
    }
  }
  (*(code *)&DAT_0af1c4d0)(&lStack_908,uVar18,lStack_3c8,uVar9);
  (*(code *)&DAT_0af0d260)(&plStack_1098);
  if (cStack_1099 != '\x02') {
    cStack_9a9 = cStack_1099;
  }
  piVar19 = aiStack_1738;
  if (aiStack_1738[0] == 2) {
    piVar19 = (int *)0x0;
  }
  piVar13 = (int *)0x0;
  if ((piVar7 != (int *)0x0) && (piVar13 = (int *)0x0, *piVar7 != 2)) {
    piVar13 = piVar7;
  }
  (*(code *)&DAT_0af1c770)(&plStack_6d8,piVar19,piVar13);
  if ((int)plStack_6d8 != 2) {
    (*(code *)&DAT_120cba68)(&plStack_368,&plStack_6d8,0xf0);
    (*(code *)&DAT_0af0cdb0)(&plStack_1098,&plStack_368);
  }
  lStack_698 = lStack_560;
  uStack_690 = uStack_558;
  uStack_6a8 = (long *)CONCAT44(uStack_56c,uStack_570);
  uStack_6a0 = (long *)CONCAT44(uStack_564,uStack_568);
  uStack_6b8 = (long *)CONCAT44(uStack_57c,uStack_580);
  uStack_6b0 = (long *)CONCAT44(uStack_574,uStack_578);
  uStack_6c8 = (long *)CONCAT44(uStack_58c,uStack_590);
  uStack_6c0 = (long *)CONCAT44(uStack_584,uStack_588);
  plStack_6d8 = plStack_5a0;
  plStack_6d0 = plStack_598;
  func_0x068b1c40(&plStack_368,&plStack_1098,&plStack_6d8,plStack_98,plStack_a8,lVar5,lVar15);
  plVar28 = plStack_368;
  plStack_518 = plStack_360;
  plStack_510 = plStack_358;
  plStack_508 = plStack_350;
  plStack_500 = plStack_348;
  plStack_4f8 = plStack_340;
  plStack_4f0 = plStack_338;
  plStack_4e8 = plStack_330;
  lStack_4e0 = lStack_328;
  plStack_4d8 = plStack_320;
  plStack_4d0 = plStack_318;
  if (plStack_368 == (long *)0xffffffffffffffff) {
    plStack_240 = plStack_360;
    plStack_238 = plStack_358;
    plStack_230 = plStack_350;
    plStack_228 = plStack_348;
    plStack_220 = plStack_340;
    plStack_218 = plStack_338;
    uStack_210 = plStack_330;
    uStack_208 = lStack_328;
    uStack_200 = plStack_320;
    uStack_1f8 = plStack_318;
    plStack_248 = (long *)0xffffffffffffffff;
    func_0x06fa9d30(&plStack_1098);
    uVar3 = plStack_88._0_4_;
    if ((lStack_908 != -1) && (lStack_908 != 0)) {
      (*(code *)&DAT_04732840)(uStack_900,lStack_908,1);
    }
    lVar15 = lStack_48;
    if ((lStack_8e8 != -1) && (lStack_8e8 != 0)) {
      (*(code *)&DAT_04732840)(uStack_8e0,lStack_8e8,1);
    }
    if ((lStack_8c8 != -1) && (lStack_8c8 != 0)) {
      (*(code *)&DAT_04732840)(uStack_8c0,lStack_8c8,1);
    }
    if (0 < (long)plStack_40) {
      (*(code *)&DAT_04732840)(plStack_90,plStack_40,1);
    }
    if ((undefined *)((long)plStack_38 + -1) < (undefined *)0xfffffffffffffffe) {
      (*(code *)&DAT_04732840)(lStack_70,plStack_38,1);
    }
    if ((undefined *)0xfffffffffffffffd < (undefined *)((long)plStack_68 + -1))
    goto code_r0x071d900c;
    (*(code *)&DAT_04732840)(uStack_a0,plStack_68,1);
    goto code_r0x071d900c;
  }
  (*(code *)&DAT_120cba68)(&puStack_1f0,&lStack_310,0xa8);
  plStack_240 = plStack_518;
  plStack_238 = plStack_510;
  plStack_230 = plStack_508;
  plStack_228 = plStack_500;
  plStack_220 = plStack_4f8;
  plStack_218 = plStack_4f0;
  uStack_210 = plStack_4e8;
  uStack_208 = lStack_4e0;
  uStack_200 = plStack_4d8;
  uStack_1f8 = plStack_4d0;
  lStack_148 = lStack_8c8;
  uStack_140 = uStack_8c0;
  uStack_138 = uStack_8b8;
  uStack_130 = uStack_8b0;
  lStack_128 = lStack_8e8;
  uStack_120 = uStack_8e0;
  uStack_118 = uStack_8d8;
  uStack_110 = uStack_8d0;
  uStack_f8 = uStack_8f8;
  uStack_f4 = uStack_8f4;
  uStack_f0 = uStack_8f0;
  uStack_ec = uStack_8ec;
  lStack_108 = lStack_908;
  uStack_100 = uStack_900;
  plStack_248 = plVar28;
  func_0x06fa9d30(&plStack_1098);
  if (0 < (long)plStack_40) {
    (*(code *)&DAT_04732840)(plStack_90,plStack_40,1);
  }
  if ((undefined *)((long)plStack_38 + -1) < (undefined *)0xfffffffffffffffe) {
    (*(code *)&DAT_04732840)(lStack_70,plStack_38,1);
  }
  if ((undefined *)((long)plStack_68 + -1) < (undefined *)0xfffffffffffffffe) {
    (*(code *)&DAT_04732840)(uStack_a0,plStack_68,1);
  }
  (*(code *)&DAT_0aee8990)(lStack_48,(ulong)plStack_88 & 0xffffffff,param_8 != 0,&plStack_248);
  plVar23 = plStack_240;
  plStack_888 = plStack_238;
  plStack_880 = plStack_230;
  plStack_878 = plStack_228;
  plStack_4a8 = plStack_220;
  plStack_4a0 = plStack_218;
  uStack_498 = uStack_210;
  uStack_490 = uStack_208;
  plStack_488 = uStack_200;
  plStack_480 = uStack_1f8;
  (*(code *)&DAT_120cba68)(&uStack_7e0,&puStack_1f0,0x108);
  plVar16 = plStack_888;
  plStack_830 = plVar23;
  plStack_828 = plStack_888;
  uStack_820 = plStack_880;
  plStack_818 = plStack_878;
  plStack_810 = plStack_4a8;
  plStack_808 = plStack_4a0;
  uStack_800 = (undefined4)uStack_498;
  uStack_7fc = uStack_498._4_4_;
  uStack_7f8 = (undefined4)uStack_490;
  uStack_7f4 = uStack_490._4_4_;
  plStack_7f0 = plStack_488;
  plStack_7e8 = plStack_480;
  plStack_838 = plVar28;
  plStack_358 = plStack_4b0;
  plStack_368 = plStack_4c0;
  plStack_360 = plStack_4b8;
  if ((int)lStack_b8 != 2) {
    puVar29 = (undefined *)param_7[0x94];
    lVar15 = param_7[0x95];
    if ((*(char *)((long)param_7 + 0x734) == '\x01') &&
       (cVar4 = (*(code *)&DAT_06c36c20)(puVar29,lVar15), cVar4 != '\0')) {
      lVar15 = 0xc;
      puVar29 = &UNK_006de48d;
    }
    plVar28 = (long *)(*(code *)&DAT_06c36bf0)(puVar29,lVar15);
    if (*plVar28 != -1) {
      bVar30 = (*(byte *)((long)plVar28 + 0x79) & 1) == 0;
      uStack_820._0_2_ = (ushort)(byte)uStack_820;
      if (bVar30) {
        func_0x075885d0(&plStack_368,cStack_73f);
        plStack_238 = plStack_358;
        plStack_248 = plStack_368;
        plStack_240 = plStack_360;
      }
      else {
        plStack_1080 = plStack_360 + (long)plStack_358 * 3;
        plStack_1098 = plStack_360;
        plStack_1090 = plStack_360;
        plStack_1088 = plStack_368;
        func_0x064276a0(&plStack_248,&plStack_1098);
      }
      uStack_820 = (long *)CONCAT71(uStack_820._1_7_,!bVar30);
      func_0x07c7ec00(&plStack_838);
      if (plStack_838 != (long *)0x0) {
        (*(code *)&DAT_04732840)(plStack_830,(long)plStack_838 * 0x18,8);
      }
      plStack_828 = plStack_238;
      plStack_838 = plStack_248;
      plStack_830 = plStack_240;
      func_0x075882d0(&plStack_838);
      goto code_r0x071d9c55;
    }
  }
  if ((uStack_820._1_1_ == '\x03') && ((byte)uStack_820 == '\0')) {
    plStack_1088 = plStack_358;
    plStack_1098 = plStack_368;
    plStack_1090 = plStack_360;
    func_0x07c7ec00(&plStack_838);
    if (plStack_838 != (long *)0x0) {
      (*(code *)&DAT_04732840)(plStack_830,(long)plStack_838 * 0x18,8);
    }
    plStack_828 = plStack_1088;
    plStack_838 = plStack_1098;
    plStack_830 = plStack_1090;
    func_0x075885d0(&plStack_838,cStack_73f);
  }
  else {
    if (((int)lStack_b8 != 2) && (cStack_73f != '\0')) {
      func_0x075885d0(&plStack_838,1);
    }
    func_0x07c7ec00(&plStack_368);
    if (plStack_368 != (long *)0x0) {
      (*(code *)&DAT_04732840)(plStack_360,(long)plStack_368 * 0x18,8);
    }
  }
  func_0x075882d0(&plStack_838);
  if ((plVar16 != (long *)0x0) && ((byte)uStack_820 != '\0')) {
    func_0x075875b0(&plStack_838);
  }
code_r0x071d9c55:
  if (((int)plStack_58[0x2e] != 2) && (*(char *)((long)plStack_58 + 0x1e2) == '\0')) {
    func_0x07abab10(&plStack_838,&uStack_49);
  }
  func_0x07c399d0(&plStack_1098,&plStack_838);
  if (plStack_1088 != (long *)0x0) {
    func_0x07587fd0(&plStack_1098);
  }
  if (cStack_73b == '\x02') {
    func_0x07abbdc0(&plStack_838,&uStack_49);
  }
  plVar28 = plStack_830;
  plVar23 = plStack_838;
  plStack_e8 = plStack_828;
  plStack_e0 = uStack_820;
  plStack_d8 = plStack_818;
  plStack_458 = plStack_810;
  plStack_450 = plStack_808;
  uStack_448 = (long *)CONCAT44(uStack_7fc,uStack_800);
  uStack_440 = CONCAT44(uStack_7f4,uStack_7f8);
  uStack_438 = plStack_7f0;
  uStack_430 = plStack_7e8;
  (*(code *)&DAT_120cba68)(auStack_1848,&uStack_7e0,0xa8);
  plStack_17a0 = plStack_1098;
  plStack_1798 = plStack_1090;
  plStack_1790 = plStack_1088;
  if ((lStack_738 != -1) && (lStack_738 != 0)) {
    (*(code *)&DAT_04732840)(uStack_730,lStack_738,1);
  }
  if ((lStack_718 != -1) && (lStack_718 != 0)) {
    (*(code *)&DAT_04732840)(uStack_710,lStack_718,1);
  }
  if ((lStack_6f8 != -1) && (lStack_6f8 != 0)) {
    (*(code *)&DAT_04732840)(uStack_6f0,lStack_6f8,1);
  }
  func_0x06fa9d30(&plStack_1788);
  func_0x07819d60(&plStack_478);
  lVar15 = lStack_c0;
joined_r0x071d9dc7:
  lStack_c0 = lVar15;
  if (lVar15 != 0) {
    puVar27 = (undefined8 *)(lStack_c8 + 8);
    do {
      if (puVar27[-1] != 0) {
        (*(code *)&DAT_04732840)(*puVar27,puVar27[-1],1);
      }
      puVar27 = puVar27 + 3;
      lVar15 = lVar15 + -1;
    } while (lVar15 != 0);
  }
  if (lStack_d0 != 0) {
    (*(code *)&DAT_04732840)(lStack_c8,lStack_d0 * 0x18,8);
  }
  plStack_428 = plStack_e8;
  plStack_420 = plStack_e0;
  plStack_418 = plStack_d8;
  plStack_868 = plStack_458;
  plStack_860 = plStack_450;
  uStack_858 = (undefined4)uStack_448;
  uStack_854 = uStack_448._4_4_;
  uStack_850 = (undefined4)uStack_440;
  uStack_84c = uStack_440._4_4_;
  uStack_848 = (undefined4)uStack_438;
  uStack_844 = uStack_438._4_4_;
  uStack_840 = (undefined4)uStack_430;
  uStack_83c = uStack_430._4_4_;
  if (plVar23 == (long *)0xffffffffffffffff) {
    plStack_1080 = plStack_d8;
    plStack_1090 = plStack_e8;
    plStack_1088 = plStack_e0;
    plStack_1078 = plStack_458;
    plStack_1070 = plStack_450;
    plStack_1068 = uStack_448;
    uStack_1060 = (undefined4)uStack_440;
    uStack_105c = uStack_440._4_4_;
    uStack_1058 = (undefined4)uStack_438;
    uStack_1054 = uStack_438._4_4_;
    uStack_1050 = (undefined4)uStack_430;
    uStack_104c = uStack_430._4_4_;
    plStack_1098 = plVar28;
    uVar9 = func_0x0698f010(&plStack_1098);
    puStack_b0[1] = uVar9;
    *puStack_b0 = 0xffffffffffffffff;
    return puStack_b0;
  }
  (*(code *)&DAT_120cba68)(&puStack_1f0,auStack_1848,0xc0);
  puVar27 = puStack_b0;
  cVar4 = cStack_14c;
  plStack_238 = plStack_428;
  plStack_230 = plStack_420;
  plStack_228 = plStack_418;
  plStack_220 = plStack_868;
  plStack_218 = plStack_860;
  uStack_210 = (long *)CONCAT44(uStack_854,uStack_858);
  uStack_208 = CONCAT44(uStack_84c,uStack_850);
  uStack_200 = (long *)CONCAT44(uStack_844,uStack_848);
  uStack_1f8 = (long *)CONCAT44(uStack_83c,uStack_840);
  uStack_130 = uStack_130 & 0xffffffffffffff00;
  plStack_240 = plVar28;
  plStack_248 = plVar23;
  if ((param_10 == 0) && (plStack_418 != (long *)0xffffffffffffffff)) {
    uVar9 = func_0x0682b0f0(&UNK_006eb263,0x2b);
    puVar27 = puStack_b0;
code_r0x071da7dd:
    puVar27[1] = uVar9;
    *puVar27 = 0xffffffffffffffff;
    func_0x06fbd380(&plStack_248);
    func_0x07c7ec00(&lStack_148);
    if (lStack_148 == 0) {
      return puVar27;
    }
    (*(code *)&DAT_04732840)(uStack_140,lStack_148 * 0x18,8);
    return puVar27;
  }
  if (cStack_14c != '\x02' && param_12 == '\0') {
    uVar9 = func_0x0682b0f0(&UNK_006eb28e,0x38);
    goto code_r0x071da7dd;
  }
  lStack_48 = CONCAT71(lStack_48._1_7_,uStack_14f);
  plStack_88 = (long *)CONCAT71(plStack_88._1_7_,uStack_14b);
  uStack_498 = plStack_1790;
  plStack_4a8 = plStack_17a0;
  plStack_4a0 = plStack_1798;
  func_0x07b487c0(&plStack_1098,&plStack_248,0);
  if ((int)*param_7 == 2) goto code_r0x071da684;
  plVar28 = (long *)param_7[0x94];
  plVar16 = (long *)param_7[0x95];
  if (*(char *)((long)param_7 + 0x734) == '\x01') {
    plVar23 = (long *)(*(code *)&DAT_06c60840)(plVar28,plVar16);
    if (plVar23 != (long *)0x0) {
      if (*plVar23 != -1) {
        plVar16 = (long *)0xc;
      }
      if ((int)*plVar23 != -1) {
        plVar28 = (long *)&UNK_006de48d;
      }
      goto code_r0x071d9f8a;
    }
  }
  else {
code_r0x071d9f8a:
    puVar8 = (undefined8 *)(*(code *)&DAT_06c60840)(plVar28,plVar16);
    if (puVar8 != (undefined8 *)0x0) goto code_r0x071d9f9f;
  }
code_r0x071da78e:
  plVar26 = (long *)&UNK_006cd078;
  (*(code *)&DAT_120a43e0)(&UNK_006cd078,0x31,&UNK_121357f0);
  plVar25 = param_7;
code_r0x071da7a7:
  plVar23 = (long *)0x0;
code_r0x071da7ab:
  uStack_210 = (long *)0x0;
  plStack_240 = plVar16;
  plStack_238 = plVar26;
  plStack_218 = plVar25;
  plStack_230 = plVar28;
  plStack_228 = plVar23;
  plStack_220 = (long *)0x0;
code_r0x071d91d3:
  uStack_1f8 = plStack_898;
  uStack_208 = lStack_8a8;
  uStack_200 = plStack_8a0;
  plStack_248 = (long *)0xffffffffffffffff;
  if ((plStack_408 != (long *)0xffffffffffffffff) && (plStack_408 != (long *)0x0)) {
    (*(code *)&DAT_04732840)(plStack_400,plStack_408,1);
  }
  lVar15 = lStack_48;
  lVar5 = CONCAT44(iStack_3ec,iStack_3f0);
  uVar3 = plStack_88._0_4_;
  if ((lVar5 != -1) && (lVar5 != 0)) {
    (*(code *)&DAT_04732840)(CONCAT44(iStack_3e4,iStack_3e8),lVar5,1);
  }
  lVar5 = CONCAT44(iStack_3d4,iStack_3d8);
  if ((lVar5 != -1) && (lVar5 != 0)) {
    (*(code *)&DAT_04732840)(CONCAT44(iStack_3cc,iStack_3d0),lVar5,1);
  }
  if ((lStack_3c0 != -1) && (lStack_3c0 != 0)) {
    (*(code *)&DAT_04732840)(uStack_3b8,lStack_3c0,1);
  }
  if ((lStack_3a8 != -1) && (lStack_3a8 != 0)) {
    (*(code *)&DAT_04732840)(uStack_3a0,lStack_3a8,1);
  }
  lVar5 = lStack_390;
  if ((lStack_390 != -1) && (func_0x07c7ec00(&lStack_390), lVar5 != 0)) {
    (*(code *)&DAT_04732840)(uStack_388,lVar5 * 0x18,8);
  }
code_r0x071d900c:
  (*(code *)&DAT_0aee8990)(lVar15,uVar3,param_8 != 0,&plStack_248);
  plVar28 = plStack_240;
  plStack_4a8 = plStack_220;
  plStack_4a0 = plStack_218;
  uStack_498 = uStack_210;
  uStack_490 = uStack_208;
  plStack_e8 = plStack_238;
  plStack_e0 = plStack_230;
  plStack_d8 = plStack_228;
  plStack_458 = plStack_220;
  plStack_450 = plStack_218;
  uStack_448 = uStack_210;
  uStack_440 = uStack_208;
  uStack_438 = uStack_200;
  uStack_430 = uStack_1f8;
  func_0x06fa9d30(&plStack_1788);
  func_0x07819d60(&plStack_478);
  plVar16 = plStack_4b8;
  if (plStack_4b0 != (long *)0x0) {
code_r0x071d81e2:
    plVar16 = plStack_4b8;
    plVar23 = plStack_4b8 + 1;
    plVar26 = plStack_4b0;
    do {
      if (plVar23[-1] != 0) {
        (*(code *)&DAT_04732840)(*plVar23,plVar23[-1],1);
      }
      plVar23 = plVar23 + 3;
      plVar26 = (long *)((long)plVar26 + -1);
    } while (plVar26 != (long *)0x0);
  }
code_r0x071d90ad:
  plVar23 = (long *)0xffffffffffffffff;
  lVar15 = lStack_c0;
  if (plStack_4c0 != (long *)0x0) {
    (*(code *)&DAT_04732840)(plVar16,(long)plStack_4c0 * 0x18,8);
    lVar15 = lStack_c0;
  }
  goto joined_r0x071d9dc7;
code_r0x071d9f9f:
  if ((long *)*puVar8 == (long *)0xffffffffffffffff) {
code_r0x071da684:
    (*(code *)&DAT_120cba68)(&plStack_1788,&plStack_1098,0x178);
code_r0x071da69d:
    (*(code *)&DAT_120cba68)(&plStack_1098,&plStack_1788,0x178);
    plStack_f20 = plStack_4a8;
    plStack_f18 = plStack_4a0;
    plStack_f10 = uStack_498;
    (*(code *)&DAT_120cba68)(puVar27,&plStack_1098,400);
    *(undefined1 *)(puVar27 + 0x32) = (undefined1)lStack_48;
    *(char *)((long)puVar27 + 0x191) = cVar4;
    *(undefined1 *)((long)puVar27 + 0x192) = plStack_88._0_1_;
    return puVar27;
  }
  plStack_830 = (long *)puVar8[1];
  plStack_828 = (long *)puVar8[2];
  uStack_820 = (long *)puVar8[3];
  plStack_818 = (long *)puVar8[4];
  plStack_810 = (long *)puVar8[5];
  plStack_808 = (long *)puVar8[6];
  uStack_800 = *(undefined4 *)(puVar8 + 7);
  uStack_7fc = *(undefined4 *)((long)puVar8 + 0x3c);
  uStack_7f8 = *(undefined4 *)(puVar8 + 8);
  uStack_7f4 = *(undefined4 *)((long)puVar8 + 0x44);
  plStack_7f0 = (long *)puVar8[9];
  plStack_7e8 = (long *)puVar8[10];
  uStack_7e0 = puVar8[0xb];
  uStack_7d8 = puVar8[0xc];
  uStack_7d0 = puVar8[0xd];
  uStack_7c8 = puVar8[0xe];
  uStack_7c0 = puVar8[0xf];
  plStack_838 = (long *)*puVar8;
  func_0x07ac0cb0(&plStack_1078,&uStack_49);
  (*(code *)&DAT_06c4c620)(&plStack_1770,&plStack_838);
  plStack_1758 = (long *)0xffffffffffffffff;
  uStack_1740 = 0xffffffffffffffff;
  uStack_1728 = 0xffffffffffffffff;
  uStack_1710 = 0xffffffffffffffff;
  uStack_16b0 = 0;
  uStack_16a0 = 0xff;
  plStack_16f8 = (long *)0xffffffffffffffff;
  plStack_1788 = (long *)0x0;
  plStack_1780 = (long *)0x8;
  plStack_1778 = (long *)0x0;
  uStack_1698 = 0;
  (*(code *)&DAT_04732870)();
  puVar27 = (undefined8 *)(*(code *)&DAT_04732830)(0x11,1);
  if (puVar27 == (undefined8 *)0x0) {
code_r0x071da83e:
    (*(code *)&DAT_1208422d)(1,0x11);
    goto code_r0x071da84e;
  }
  *puVar27 = 0x646f6d5f65646f63;
  puVar27[1] = 0x6c69666f72705f65;
  *(undefined1 *)(puVar27 + 2) = 0x65;
  plStack_368 = (long *)0x11;
  plStack_358 = (long *)0x11;
  plStack_360 = puVar27;
  (*(code *)&DAT_0d90ef90)(&plStack_1758,&plStack_368);
  plStack_368 = plStack_1788;
  plStack_360 = plStack_1780;
  plStack_358 = plStack_1778;
  plStack_350 = plStack_1770;
  plStack_348 = plStack_1768;
  plStack_340 = plStack_1760;
  plStack_338 = plStack_1758;
  plStack_330 = plStack_1750;
  lStack_328 = lStack_1748;
  plStack_6d8 = plStack_16f8;
  plStack_6d0 = plStack_16f0;
  uStack_6c8 = plStack_16e8;
  uStack_6c0 = plStack_16e0;
  uStack_6b8 = plStack_16d8;
  uStack_6b0 = plStack_16d0;
  uStack_6a8 = plStack_16c8;
  uStack_6a0 = plStack_16c0;
  lStack_698 = lStack_16b8;
  uStack_3f8 = (long *)CONCAT71(uStack_1697,uStack_1698);
  plStack_400 = (long *)CONCAT71(uStack_169f,uStack_16a0);
  plStack_408 = plStack_16a8;
  (*(code *)&DAT_04732870)();
  puVar27 = (undefined8 *)(*(code *)&DAT_04732830)(9,1);
  if (puVar27 != (undefined8 *)0x0) {
    *puVar27 = 0x65706f6c65766564;
    *(undefined1 *)(puVar27 + 1) = 0x72;
    plStack_1788 = (long *)0x9;
    plStack_1778 = (long *)0x9;
    plStack_1780 = puVar27;
    (*(code *)&DAT_0d90ef90)(&plStack_5e8,&plStack_1788);
    plVar23 = plStack_5d8;
    plVar16 = plStack_5e0;
    plVar28 = plStack_5e8;
    plStack_1788 = plStack_368;
    plStack_1780 = plStack_360;
    plStack_1778 = plStack_358;
    plStack_1770 = plStack_350;
    plStack_1768 = plStack_348;
    plStack_1760 = plStack_340;
    plStack_1758 = plStack_338;
    plStack_1750 = plStack_330;
    lStack_1748 = lStack_328;
    plStack_5e8 = plStack_6d8;
    plStack_5e0 = plStack_6d0;
    plStack_5d8 = uStack_6c8;
    plStack_5d0 = uStack_6c0;
    plStack_5c8 = uStack_6b8;
    plStack_5c0 = uStack_6b0;
    plStack_5b8 = uStack_6a8;
    plStack_5b0 = uStack_6a0;
    lStack_5a8 = lStack_698;
    plStack_998 = uStack_3f8;
    plStack_9a8 = plStack_408;
    plStack_9a0 = plStack_400;
    (*(code *)&DAT_04732870)();
    puVar27 = (undefined8 *)(*(code *)&DAT_04732830)(0x11,1);
    if (puVar27 != (undefined8 *)0x0) {
      plStack_40 = plVar23;
      plStack_a8 = plVar16;
      plStack_98 = plVar28;
      *puVar27 = 0x646f6d5f65646f63;
      puVar27[1] = 0x6c69666f72705f65;
      *(undefined1 *)(puVar27 + 2) = 0x65;
      plStack_368 = (long *)0x11;
      plStack_358 = (long *)0x11;
      plStack_360 = puVar27;
      (*(code *)&DAT_0d90ef90)(&plStack_6d8,&plStack_368);
      plStack_38 = plStack_6d8;
      plStack_58 = plStack_6d0;
      plStack_68 = uStack_6c8;
      plStack_368 = plStack_1788;
      plStack_360 = plStack_1780;
      plStack_358 = plStack_1778;
      plStack_350 = plStack_1770;
      plStack_348 = plStack_1768;
      plStack_340 = plStack_1760;
      plStack_338 = plStack_1758;
      plStack_330 = plStack_1750;
      lStack_328 = lStack_1748;
      plStack_6d8 = plStack_5e8;
      plStack_6d0 = plStack_5e0;
      uStack_6c8 = plStack_5d8;
      uStack_6c0 = plStack_5d0;
      uStack_6b8 = plStack_5c8;
      uStack_6b0 = plStack_5c0;
      uStack_6a8 = plStack_5b8;
      uStack_6a0 = plStack_5b0;
      lStack_698 = lStack_5a8;
      plStack_508 = plStack_998;
      plStack_518 = plStack_9a8;
      plStack_510 = plStack_9a0;
      (*(code *)&DAT_04732870)();
      plVar28 = (long *)(*(code *)&DAT_04732830)(0xd,1);
      if (plVar28 != (long *)0x0) {
        *(undefined8 *)((long)plVar28 + 5) = 0x74726174735f6e6f;
        *plVar28 = 0x5f6e6f6973736573;
        plStack_1788 = (long *)0xd;
        plStack_1778 = (long *)0xd;
        plStack_1780 = plVar28;
        (*(code *)&DAT_0d90ef90)(&plStack_5e8,&plStack_1788);
        plVar23 = plStack_5d8;
        plVar16 = plStack_5e0;
        plVar28 = plStack_5e8;
        plStack_5e8 = plStack_368;
        plStack_5e0 = plStack_360;
        plStack_5d8 = plStack_358;
        plStack_5d0 = plStack_350;
        plStack_5c8 = plStack_348;
        plStack_5c0 = plStack_340;
        plStack_5b8 = plStack_338;
        plStack_5b0 = plStack_330;
        lStack_5a8 = lStack_328;
        plStack_408 = plStack_6d8;
        plStack_400 = plStack_6d0;
        uStack_3f8 = uStack_6c8;
        iStack_3f0 = (int)uStack_6c0;
        iStack_3ec = uStack_6c0._4_4_;
        iStack_3e8 = (int)uStack_6b8;
        iStack_3e4 = uStack_6b8._4_4_;
        iStack_3e0 = (int)uStack_6b0;
        iStack_3dc = uStack_6b0._4_4_;
        iStack_3d8 = (int)uStack_6a8;
        iStack_3d4 = uStack_6a8._4_4_;
        iStack_3d0 = (int)uStack_6a0;
        iStack_3cc = uStack_6a0._4_4_;
        lStack_3c8 = lStack_698;
        plStack_998 = plStack_508;
        plStack_9a8 = plStack_518;
        plStack_9a0 = plStack_510;
        if (plStack_1068 == plStack_1078) {
          (*(code *)&DAT_0c12f9d0)(&plStack_1078);
        }
        plStack_1070[(long)plStack_1068 * 0x1f + 8] = lStack_5a8;
        plStack_1070[(long)plStack_1068 * 0x1f + 6] = (long)plStack_5b8;
        (plStack_1070 + (long)plStack_1068 * 0x1f + 6)[1] = (long)plStack_5b0;
        plStack_1070[(long)plStack_1068 * 0x1f + 4] = (long)plStack_5c8;
        (plStack_1070 + (long)plStack_1068 * 0x1f + 4)[1] = (long)plStack_5c0;
        plStack_1070[(long)plStack_1068 * 0x1f + 2] = (long)plStack_5d8;
        (plStack_1070 + (long)plStack_1068 * 0x1f + 2)[1] = (long)plStack_5d0;
        plStack_1070[(long)plStack_1068 * 0x1f] = (long)plStack_5e8;
        (plStack_1070 + (long)plStack_1068 * 0x1f)[1] = (long)plStack_5e0;
        plStack_1070[(long)plStack_1068 * 0x1f + 9] = (long)plStack_98;
        plStack_1070[(long)plStack_1068 * 0x1f + 10] = (long)plStack_a8;
        plStack_1070[(long)plStack_1068 * 0x1f + 0xb] = (long)plStack_40;
        plStack_1070[(long)plStack_1068 * 0x1f + 0xc] = (long)plStack_38;
        plStack_1070[(long)plStack_1068 * 0x1f + 0xd] = (long)plStack_58;
        plStack_1070[(long)plStack_1068 * 0x1f + 0xe] = (long)plStack_68;
        plStack_1070[(long)plStack_1068 * 0x1f + 0xf] = (long)plVar28;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x10] = (long)plVar16;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x11] = (long)plVar23;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x12] = (long)plStack_408;
        (plStack_1070 + (long)plStack_1068 * 0x1f + 0x12)[1] = (long)plStack_400;
        plVar28 = plStack_1070 + (long)plStack_1068 * 0x1f + 0x14;
        *(int *)plVar28 = (int)uStack_3f8;
        *(int *)((long)plVar28 + 4) = uStack_3f8._4_4_;
        *(int *)(plVar28 + 1) = iStack_3f0;
        *(int *)((long)plVar28 + 0xc) = iStack_3ec;
        plVar28 = plStack_1070 + (long)plStack_1068 * 0x1f + 0x16;
        *(int *)plVar28 = iStack_3e8;
        *(int *)((long)plVar28 + 4) = iStack_3e4;
        *(int *)(plVar28 + 1) = iStack_3e0;
        *(int *)((long)plVar28 + 0xc) = iStack_3dc;
        plVar28 = plStack_1070 + (long)plStack_1068 * 0x1f + 0x18;
        *(int *)plVar28 = iStack_3d8;
        *(int *)((long)plVar28 + 4) = iStack_3d4;
        *(int *)(plVar28 + 1) = iStack_3d0;
        *(int *)((long)plVar28 + 0xc) = iStack_3cc;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x1a] = lStack_3c8;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x1b] = 0xbe00000001;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x1e] = (long)plStack_998;
        plStack_1070[(long)plStack_1068 * 0x1f + 0x1c] = (long)plStack_9a8;
        (plStack_1070 + (long)plStack_1068 * 0x1f + 0x1c)[1] = (long)plStack_9a0;
        plStack_1068 = (long *)((long)plStack_1068 + 1);
        (*(code *)&DAT_120cba68)(&plStack_1788,&plStack_1098,0x178);
        puVar27 = puStack_b0;
        goto code_r0x071da69d;
      }
      goto code_r0x071da86b;
    }
    goto code_r0x071da83e;
  }
  goto code_r0x071da85b;
}

