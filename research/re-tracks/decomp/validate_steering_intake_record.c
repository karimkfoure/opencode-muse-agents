/* validate_steering_intake_record @ 0971a2e0 | undefined8 *validate_steering_intake_record(undefined8 *param_1,undefined8 param_2,undefined8 param_3,uint param_4,char *param_5); */

undefined8 *
validate_steering_intake_record
          (undefined8 *param_1,undefined8 param_2,undefined8 param_3,uint param_4,char *param_5)

{
  long *plVar1;
  undefined8 **ppuVar2;
  byte bVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  long lVar13;
  long extraout_RDX;
  undefined8 *puVar14;
  long lVar15;
  undefined1 auVar16 [16];
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  undefined4 uStack_2f8;
  undefined4 uStack_2f4;
  undefined4 uStack_2f0;
  undefined4 uStack_2ec;
  undefined8 *puStack_280;
  undefined8 *puStack_278;
  undefined1 *puStack_270;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined8 uStack_258;
  long lStack_250;
  undefined8 uStack_248;
  undefined8 uStack_240;
  long lStack_238;
  undefined8 uStack_230;
  undefined8 uStack_228;
  long lStack_220;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined8 *puStack_1b0;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 *puStack_188;
  undefined1 *puStack_180;
  undefined1 *puStack_178;
  code *pcStack_170;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  uint uStack_ec;
  long lStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  long lStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 *puStack_b8;
  undefined1 *puStack_b0;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [8];
  
  uStack_c8 = param_2;
  uStack_c0 = param_3;
  if (*param_5 == -1) {
    puStack_280 = &uStack_c8;
    puStack_278 = (undefined8 *)&LAB_09eaed40;
    FUN_12089060(&uStack_168,&UNK_0035d788,&puStack_280);
    FUN_09e96200(&puStack_280,CONCAT44(uStack_15c,uStack_160),CONCAT44(uStack_154,uStack_158));
    if (CONCAT44(uStack_164,uStack_168) != 0) {
      thunk_FUN_120b3329(CONCAT44(uStack_15c,uStack_160),CONCAT44(uStack_164,uStack_168),1);
    }
    param_1[4] = CONCAT44(uStack_264,uStack_268);
    param_1[5] = CONCAT44(uStack_25c,uStack_260);
    param_1[2] = puStack_278;
    param_1[3] = puStack_270;
    param_1[1] = puStack_280;
    goto LAB_0971a8dc;
  }
  uStack_1d8 = param_2;
  uStack_1d0 = param_3;
  uStack_ec = param_4;
  if ((0x4cU >> (param_4 & 0x1f) & 1) == 0) {
    if ((0xb0U >> (param_4 & 0x1f) & 1) == 0) {
      FUN_0954a1d0(&uStack_168,param_2,param_3,param_5);
      puVar14 = (undefined8 *)CONCAT44(uStack_164,uStack_168);
      if (puVar14 == (undefined8 *)0xffffffffffffffff) goto LAB_0971a7e6;
      uStack_68 = CONCAT44(uStack_13c,uStack_140);
      puStack_b8 = (undefined8 *)CONCAT44(uStack_15c,uStack_160);
      puStack_b0 = (undefined1 *)CONCAT44(uStack_154,uStack_158);
      uStack_78 = CONCAT44(uStack_14c,uStack_150);
      uStack_1a8 = uStack_138;
      uStack_1a4 = uStack_134;
      uStack_1a0 = CONCAT44(uStack_12c,uStack_130);
      uStack_198 = uStack_128;
      uStack_308 = uStack_118;
      uStack_304 = uStack_114;
      uStack_300 = uStack_110;
      uStack_2fc = uStack_10c;
    }
    else {
      FUN_0954a330();
      puVar14 = (undefined8 *)CONCAT44(uStack_164,uStack_168);
      if (puVar14 == (undefined8 *)0xffffffffffffffff) {
LAB_0971a7e6:
        puStack_188 = &uStack_1d8;
        puStack_180 = &LAB_09eaed40;
        puStack_178 = auStack_38;
        pcStack_170 = FUN_0ff4e790;
        FUN_12089060(&lStack_e8,&UNK_00341362,&puStack_188);
        FUN_09e96200(&uStack_88,uStack_e0,uStack_d8);
        if (lStack_e8 != 0) {
          thunk_FUN_120b3329(uStack_e0,lStack_e8,1);
        }
        FUN_096299a0(auStack_38);
        param_1[5] = uStack_68;
        param_1[3] = uStack_78;
        param_1[4] = uStack_70;
        param_1[1] = uStack_88;
        param_1[2] = uStack_80;
LAB_0971a8dc:
        *param_1 = 0xffffffffffffffff;
        return param_1;
      }
      uStack_68 = CONCAT44(uStack_13c,uStack_140);
      puStack_b8 = (undefined8 *)CONCAT44(uStack_15c,uStack_160);
      puStack_b0 = (undefined1 *)CONCAT44(uStack_154,uStack_158);
      uStack_78 = CONCAT44(uStack_14c,uStack_150);
      uStack_1a8 = uStack_138;
      uStack_1a4 = uStack_134;
      uStack_1a0 = CONCAT44(uStack_12c,uStack_130);
      uStack_198 = uStack_128;
      uStack_120 = -1;
    }
    lStack_238 = uStack_120;
    lVar15 = -1;
    uStack_70._0_4_ = uStack_148;
    uStack_70._4_4_ = uStack_144;
  }
  else {
    FUN_0954a480(&uStack_168,param_2,param_3,param_5);
    puVar14 = (undefined8 *)CONCAT44(uStack_164,uStack_168);
    if (puVar14 == (undefined8 *)0xffffffffffffffff) goto LAB_0971a7e6;
    uStack_68 = CONCAT44(uStack_13c,uStack_140);
    puStack_b8 = (undefined8 *)CONCAT44(uStack_15c,uStack_160);
    puStack_b0 = (undefined1 *)CONCAT44(uStack_154,uStack_158);
    uStack_78 = CONCAT44(uStack_14c,uStack_150);
    uStack_70._0_4_ = uStack_148;
    uStack_70._4_4_ = uStack_144;
    uStack_1a8 = uStack_138;
    uStack_1a4 = uStack_134;
    uStack_1a0 = CONCAT44(uStack_12c,uStack_130);
    uStack_198 = uStack_128;
    uStack_2f8 = uStack_118;
    uStack_2f4 = uStack_114;
    uStack_2f0 = uStack_110;
    uStack_2ec = uStack_10c;
    lStack_238 = -1;
    lVar15 = uStack_120;
  }
  uStack_1c8 = (undefined4)uStack_78;
  uStack_1c4 = (undefined4)((ulong)uStack_78 >> 0x20);
  uStack_258 = uStack_68;
  puStack_278 = puStack_b8;
  puStack_270 = puStack_b0;
  uStack_268 = uStack_1c8;
  uStack_264 = uStack_1c4;
  uStack_260 = (undefined4)uStack_70;
  uStack_25c = uStack_70._4_4_;
  uStack_248 = uStack_1a0;
  uStack_240 = uStack_198;
  uStack_230 = CONCAT44(uStack_304,uStack_308);
  uStack_228 = CONCAT44(uStack_2fc,uStack_300);
  uStack_218 = uStack_2f8;
  uStack_214 = uStack_2f4;
  uStack_210 = uStack_2f0;
  uStack_20c = uStack_2ec;
  puStack_1b0 = puStack_b8;
  puStack_280 = puVar14;
  lStack_220 = lVar15;
  uStack_148 = (undefined4)uStack_70;
  uStack_144 = uStack_70._4_4_;
  lStack_d0 = lStack_238;
  FUN_09e96940(&uStack_168,uStack_c8,uStack_c0,&UNK_008dbb37,9,puStack_b8,puStack_b0);
  uVar11 = uStack_154;
  uVar9 = uStack_158;
  uVar7 = uStack_15c;
  uVar5 = uStack_160;
  lVar13 = CONCAT44(uStack_164,uStack_168);
  uStack_88 = (undefined8 *)CONCAT44(uStack_15c,uStack_160);
  uStack_80._0_4_ = uStack_158;
  uStack_80._4_4_ = uStack_154;
  if (lVar13 == -1) {
    uVar4 = CONCAT44(uStack_25c,uStack_260);
    FUN_09e963a0(&uStack_168,uStack_c8,uStack_c0,&UNK_008dbb53,9,uVar4,uStack_258);
    uVar12 = uStack_154;
    uVar10 = uStack_158;
    uVar8 = uStack_15c;
    uVar6 = uStack_160;
    lVar13 = CONCAT44(uStack_164,uStack_168);
    uStack_88 = (undefined8 *)CONCAT44(uStack_15c,uStack_160);
    uStack_80._0_4_ = uStack_158;
    uStack_80._4_4_ = uStack_154;
    if (lVar13 != -1) goto LAB_0971a71e;
    FUN_09ed8ed0(uStack_248,uStack_240);
    if (extraout_RDX != 0) {
      plVar1 = (long *)&uStack_268;
      uStack_78 = uStack_198;
      uStack_88 = (undefined8 *)CONCAT44(uStack_1a4,uStack_1a8);
      uStack_80._0_4_ = (undefined4)uStack_1a0;
      uStack_80._4_4_ = uStack_1a0._4_4_;
      uStack_40 = CONCAT31(uStack_40._1_3_,(char)uStack_ec);
      uStack_70._0_4_ = 0xffffffff;
      uStack_70._4_4_ = 0xffffffff;
      uStack_58 = -1;
      if ((0x4cU >> (param_4 & 0x1f) & 1) != 0) {
        bVar3 = 1;
        if (lVar15 != -1) {
          uStack_50 = CONCAT44(uStack_214,uStack_218);
          uStack_48 = CONCAT44(uStack_20c,uStack_210);
          bVar3 = 0;
          uStack_58 = lVar15;
        }
        goto LAB_0971aa8e;
      }
      if ((0xb0U >> (param_4 & 0x1f) & 1) != 0) {
LAB_0971a9f3:
        bVar3 = 1;
LAB_0971aa8e:
        uStack_128 = uStack_48;
        uStack_120 = CONCAT44(uStack_3c,uStack_40);
        uStack_138 = (undefined4)uStack_58;
        uStack_134 = uStack_58._4_4_;
        uStack_130 = (undefined4)uStack_50;
        uStack_12c = uStack_50._4_4_;
        uStack_148 = (undefined4)uStack_68;
        uStack_144 = uStack_68._4_4_;
        uStack_140 = uStack_60;
        uStack_13c = uStack_5c;
        uStack_158 = (undefined4)uStack_78;
        uStack_154 = uStack_78._4_4_;
        uStack_150 = (undefined4)uStack_70;
        uStack_14c = uStack_70._4_4_;
        uStack_168 = (undefined4)uStack_88;
        uStack_164 = uStack_88._4_4_;
        uStack_160 = (undefined4)uStack_80;
        uStack_15c = uStack_80._4_4_;
        uStack_118 = uVar5;
        uStack_114 = uVar7;
        uStack_110 = uVar9;
        uStack_10c = uVar11;
        uStack_108 = uVar6;
        uStack_104 = uVar8;
        uStack_100 = uVar10;
        uStack_fc = uVar12;
        *(undefined4 *)(param_1 + 0xc) = uVar6;
        *(undefined4 *)((long)param_1 + 100) = uVar8;
        *(undefined4 *)(param_1 + 0xd) = uVar10;
        *(undefined4 *)((long)param_1 + 0x6c) = uVar12;
        *(undefined4 *)(param_1 + 10) = uVar5;
        *(undefined4 *)((long)param_1 + 0x54) = uVar7;
        *(undefined4 *)(param_1 + 0xb) = uVar9;
        *(undefined4 *)((long)param_1 + 0x5c) = uVar11;
        *(undefined4 *)(param_1 + 8) = (undefined4)uStack_48;
        *(undefined4 *)((long)param_1 + 0x44) = uStack_48._4_4_;
        *(undefined4 *)(param_1 + 9) = uStack_40;
        *(undefined4 *)((long)param_1 + 0x4c) = uStack_3c;
        *(undefined4 *)(param_1 + 6) = (undefined4)uStack_58;
        *(undefined4 *)((long)param_1 + 0x34) = uStack_58._4_4_;
        *(undefined4 *)(param_1 + 7) = (undefined4)uStack_50;
        *(undefined4 *)((long)param_1 + 0x3c) = uStack_50._4_4_;
        *(undefined4 *)(param_1 + 4) = (undefined4)uStack_68;
        *(undefined4 *)((long)param_1 + 0x24) = uStack_68._4_4_;
        *(undefined4 *)(param_1 + 5) = uStack_60;
        *(undefined4 *)((long)param_1 + 0x2c) = uStack_5c;
        *(undefined4 *)(param_1 + 2) = (undefined4)uStack_78;
        *(undefined4 *)((long)param_1 + 0x14) = uStack_78._4_4_;
        *(undefined4 *)(param_1 + 3) = (undefined4)uStack_70;
        *(undefined4 *)((long)param_1 + 0x1c) = uStack_70._4_4_;
        *(undefined4 *)param_1 = (undefined4)uStack_88;
        *(undefined4 *)((long)param_1 + 4) = uStack_88._4_4_;
        *(undefined4 *)(param_1 + 1) = (undefined4)uStack_80;
        *(undefined4 *)((long)param_1 + 0xc) = uStack_80._4_4_;
        if (puVar14 != (undefined8 *)0x0) {
          thunk_FUN_120b3329(puStack_1b0,puVar14,1);
        }
        if (CONCAT44(uStack_264,uStack_268) != 0) {
          thunk_FUN_120b3329(uVar4,CONCAT44(uStack_264,uStack_268),1);
        }
        if ((lStack_d0 != -1) && (lStack_d0 != 0)) {
          thunk_FUN_120b3329(uStack_230,lStack_d0,1);
        }
        if (!(bool)(bVar3 & lVar15 != -1)) {
          return param_1;
        }
        if (lVar15 == 0) {
          return param_1;
        }
        thunk_FUN_120b3329(CONCAT44(uStack_214,uStack_218),lVar15,1);
        return param_1;
      }
      if (lStack_d0 != -1) {
        auVar16 = FUN_09ed8ed0(uStack_230,uStack_228);
        if (auVar16._8_8_ != 0) {
          uStack_120 = CONCAT44(uStack_3c,uStack_40);
          uStack_128 = uStack_48;
          uStack_138 = (undefined4)uStack_58;
          uStack_134 = uStack_58._4_4_;
          uStack_130 = (undefined4)uStack_50;
          uStack_12c = uStack_50._4_4_;
          uStack_148 = (undefined4)uStack_68;
          uStack_144 = uStack_68._4_4_;
          uStack_140 = uStack_60;
          uStack_13c = uStack_5c;
          uStack_158 = (undefined4)uStack_78;
          uStack_154 = uStack_78._4_4_;
          uStack_150 = (undefined4)uStack_70;
          uStack_14c = uStack_70._4_4_;
          uStack_168 = (undefined4)uStack_88;
          uStack_164 = uStack_88._4_4_;
          uStack_160 = (undefined4)uStack_80;
          uStack_15c = uStack_80._4_4_;
          FUN_09f0fb50(&uStack_88,&uStack_168,auVar16._0_8_,auVar16._8_8_);
          goto LAB_0971a9f3;
        }
      }
      puStack_b8 = &uStack_c8;
      puStack_b0 = &LAB_09eaed40;
      FUN_09719620(&uStack_168,&UNK_002ce745,&puStack_b8);
      FUN_09e96200(param_1 + 1,CONCAT44(uStack_15c,uStack_160),CONCAT44(uStack_154,uStack_158));
      *param_1 = 0xffffffffffffffff;
      if (CONCAT44(uStack_164,uStack_168) != 0) {
        thunk_FUN_120b3329(CONCAT44(uStack_15c,uStack_160),CONCAT44(uStack_164,uStack_168),1);
      }
      FUN_09641180(&uStack_88);
      ppuVar2 = &puStack_280;
      goto joined_r0x0971a76d;
    }
    uStack_88 = &uStack_c8;
    uStack_80._0_4_ = 0x9eaed40;
    uStack_80._4_4_ = 0;
    FUN_12089060(&uStack_168,&UNK_002ce712,&uStack_88);
    FUN_09e96200(param_1 + 1,CONCAT44(uStack_15c,uStack_160),CONCAT44(uStack_154,uStack_158));
    *param_1 = 0xffffffffffffffff;
    if (CONCAT44(uStack_164,uStack_168) != 0) {
      thunk_FUN_120b3329(CONCAT44(uStack_15c,uStack_160),CONCAT44(uStack_164,uStack_168),1);
    }
  }
  else {
LAB_0971a71e:
    param_1[4] = CONCAT44(uStack_14c,uStack_150);
    param_1[5] = CONCAT44(uStack_144,uStack_148);
    *(undefined4 *)(param_1 + 2) = (undefined4)uStack_88;
    *(undefined4 *)((long)param_1 + 0x14) = uStack_88._4_4_;
    *(undefined4 *)(param_1 + 3) = (undefined4)uStack_80;
    *(undefined4 *)((long)param_1 + 0x1c) = uStack_80._4_4_;
    param_1[1] = lVar13;
    *param_1 = 0xffffffffffffffff;
  }
  if (puVar14 != (undefined8 *)0x0) {
    thunk_FUN_120b3329(puStack_1b0,puVar14,1);
  }
  plVar1 = &lStack_250;
  ppuVar2 = (undefined8 **)&uStack_268;
  puStack_280 = (undefined8 *)CONCAT44(uStack_264,uStack_268);
joined_r0x0971a76d:
  if (puStack_280 != (undefined8 *)0x0) {
    thunk_FUN_120b3329(ppuVar2[1],puStack_280,1);
  }
  if (*plVar1 != 0) {
    thunk_FUN_120b3329(plVar1[1],*plVar1,1);
  }
  if ((lStack_d0 != -1) && (lStack_d0 != 0)) {
    thunk_FUN_120b3329(uStack_230,lStack_d0,1);
  }
  if ((lVar15 != -1) && (lVar15 != 0)) {
    thunk_FUN_120b3329(CONCAT44(uStack_214,uStack_218),lVar15,1);
  }
  return param_1;
}

