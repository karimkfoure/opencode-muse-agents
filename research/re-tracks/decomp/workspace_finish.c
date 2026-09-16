
long * workspace_finish(long *param_1,long ****param_2,long *param_3,long ******param_4,
                       undefined8 *param_5)

{
  undefined4 *puVar1;
  ushort uVar2;
  ushort uVar3;
  long *****ppppplVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  long *****ppppplVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  long ****pppplVar17;
  long *plVar18;
  long ******pppppplVar19;
  long *****ppppplVar20;
  long *plVar21;
  ulong uVar22;
  long extraout_RDX;
  ulong uVar23;
  uint uVar24;
  long ******pppppplVar25;
  ulong uVar26;
  long *plVar27;
  long ******pppppplVar28;
  short sVar29;
  int iVar30;
  long lVar31;
  long ******pppppplVar32;
  long lVar33;
  bool bVar34;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  long *****ppppplStack_a0;
  long *****ppppplStack_98;
  long *****ppppplStack_90;
  long ****pppplStack_88;
  long *****ppppplStack_80;
  long lStack_78;
  long *****ppppplStack_70;
  long *plStack_68;
  long lStack_60;
  long ****pppplStack_58;
  ulong uStack_50;
  long *****ppppplStack_48;
  ulong uStack_40;
  long *plStack_38;
  
  pppppplVar25 = (long ******)*param_2;
  uVar2 = *(ushort *)((long)pppppplVar25 + 0x272);
  uVar23 = (ulong)uVar2;
  pppppplVar28 = pppppplVar25;
  plStack_68 = param_1;
  ppppplStack_48 = (long *****)param_4;
  plStack_38 = param_3;
  if (uVar23 < 0xb) {
    uStack_40 = (ulong)param_2[2];
    uVar22 = uStack_40 + 1;
    pppppplVar19 = pppppplVar25 + uStack_40 * 3 + 0x2d;
    if (uVar23 < uVar22) {
      pppppplVar19[2] = (long *****)param_3[2];
      ppppplVar20 = (long *****)param_3[1];
      *pppppplVar19 = (long *****)*param_3;
      pppppplVar19[1] = ppppplVar20;
      plStack_68 = param_1;
    }
    else {
      lVar33 = uVar23 - uStack_40;
      pppplStack_58 = param_2;
      (*(code *)&DAT_120cba9a)(pppppplVar25 + uVar22 * 3 + 0x2d,pppppplVar19,lVar33 * 0x18);
      plVar21 = plStack_68;
      uVar6 = *(undefined4 *)((long)plStack_38 + 4);
      lVar31 = plStack_38[1];
      uVar7 = *(undefined4 *)((long)plStack_38 + 0xc);
      *(int *)pppppplVar19 = (int)*plStack_38;
      *(undefined4 *)((long)pppppplVar19 + 4) = uVar6;
      *(int *)(pppppplVar19 + 1) = (int)lVar31;
      *(undefined4 *)((long)pppppplVar19 + 0xc) = uVar7;
      pppppplVar19[2] = (long *****)plStack_38[2];
      (*(code *)&DAT_120cba9a)(pppppplVar25 + uVar22 * 4,pppppplVar25 + uStack_40 * 4,lVar33 * 0x20)
      ;
      param_4 = (long ******)ppppplStack_48;
      param_2 = pppplStack_58;
      plStack_68 = plVar21;
    }
    ppppplVar20 = *param_4;
    ppppplVar14 = param_4[1];
    ppppplVar4 = param_4[3];
    pppppplVar25[uStack_40 * 4 + 2] = param_4[2];
    (pppppplVar25 + uStack_40 * 4 + 2)[1] = ppppplVar4;
    pppppplVar25[uStack_40 * 4] = ppppplVar20;
    (pppppplVar25 + uStack_40 * 4)[1] = ppppplVar14;
    *(ushort *)((long)pppppplVar25 + 0x272) = uVar2 + 1;
    lStack_78 = (long)param_2[1];
    goto code_r0x06b4def8;
  }
  uStack_40 = (ulong)param_2[2];
  uVar23 = 4;
  if ((uStack_40 < 5) || (uVar23 = uStack_40, uStack_40 == 5)) {
    lStack_60 = (long)param_2[1];
    (*(code *)&DAT_04732870)();
    pppppplVar19 = (long ******)(*(code *)&DAT_04732830)(0x278,8);
    if (pppppplVar19 != (long ******)0x0) {
      pppppplVar19[0x2c] = (long *****)0x0;
      pppppplVar32 = (long ******)(~uVar23 + (ulong)*(ushort *)((long)pppppplVar25 + 0x272));
      *(short *)((long)pppppplVar19 + 0x272) = (short)pppppplVar32;
      if (pppppplVar32 < (long ******)0xc) {
        pppplStack_58 = (long ****)pppppplVar25[uVar23 * 3 + 0x2d];
        (*(code *)&DAT_120cba68)
                  (pppppplVar19 + 0x2d,pppppplVar25 + uVar23 * 3 + 0x30,(long)pppppplVar32 * 0x18);
        (*(code *)&DAT_120cba68)
                  (pppppplVar19,pppppplVar25 + uVar23 * 4 + 4,(long)pppppplVar32 * 0x20);
        *(short *)((long)pppppplVar25 + 0x272) = (short)uVar23;
        uStack_138 = pppppplVar25[uVar23 * 3 + 0x2e];
        uStack_130 = (pppppplVar25 + uVar23 * 3 + 0x2e)[1];
        pppppplVar32 = pppppplVar25 + uVar23 * 4;
        uStack_128 = *(undefined4 *)pppppplVar32;
        uStack_124 = *(undefined4 *)((long)pppppplVar32 + 4);
        uStack_120 = *(undefined4 *)(pppppplVar32 + 1);
        uStack_11c = *(undefined4 *)((long)pppppplVar32 + 0xc);
        pppppplVar32 = pppppplVar25 + uVar23 * 4 + 2;
        uStack_118 = *(undefined4 *)pppppplVar32;
        uStack_114 = *(undefined4 *)((long)pppppplVar32 + 4);
        uStack_110 = *(undefined4 *)(pppppplVar32 + 1);
        uStack_10c = *(undefined4 *)((long)pppppplVar32 + 0xc);
        lStack_78 = lStack_60;
        goto code_r0x06b4d894;
      }
code_r0x06b4e263:
      (*(code *)&DAT_120a4440)(0,pppppplVar32,0xb,&UNK_12135920);
    }
code_r0x06b4e27a:
    (*(code *)&DAT_12088f47)(8,0x278);
code_r0x06b4e28a:
    (*(code *)&DAT_120a4420)(&UNK_121355f8);
  }
  else {
    if (uStack_40 == 6) {
      uVar23 = 5;
      uStack_40 = 0;
    }
    else {
      uStack_40 = uStack_40 - 7;
      uVar23 = 6;
    }
    lStack_60 = (long)param_2[1];
    (*(code *)&DAT_04732870)();
    pppppplVar19 = (long ******)(*(code *)&DAT_04732830)(0x278,8);
    if (pppppplVar19 == (long ******)0x0) goto code_r0x06b4e27a;
    pppppplVar19[0x2c] = (long *****)0x0;
    pppppplVar32 = (long ******)(~uVar23 + (ulong)*(ushort *)((long)pppppplVar25 + 0x272));
    *(short *)((long)pppppplVar19 + 0x272) = (short)pppppplVar32;
    if ((long ******)0xb < pppppplVar32) goto code_r0x06b4e263;
    uVar22 = (ulong)(uint)((int)uVar23 << 5);
    pppplStack_58 = (long ****)pppppplVar25[uVar23 * 3 + 0x2d];
    uStack_50 = uVar23;
    (*(code *)&DAT_120cba68)
              (pppppplVar19 + 0x2d,pppppplVar25 + uVar23 * 3 + 0x30,(long)pppppplVar32 * 0x18);
    (*(code *)&DAT_120cba68)
              (pppppplVar19,(long)pppppplVar25 + uVar22 + 0x20,(long)pppppplVar32 * 0x20);
    *(short *)((long)pppppplVar25 + 0x272) = (short)uStack_50;
    uStack_138 = pppppplVar25[uVar23 * 3 + 0x2e];
    uStack_130 = (pppppplVar25 + uVar23 * 3 + 0x2e)[1];
    puVar1 = (undefined4 *)((long)pppppplVar25 + uVar22);
    uStack_128 = *puVar1;
    uStack_124 = puVar1[1];
    uStack_120 = puVar1[2];
    uStack_11c = puVar1[3];
    puVar1 = (undefined4 *)((long)pppppplVar25 + uVar22 + 0x10);
    uStack_118 = *puVar1;
    uStack_114 = puVar1[1];
    uStack_110 = puVar1[2];
    uStack_10c = puVar1[3];
    uVar23 = (ulong)*(ushort *)((long)pppppplVar19 + 0x272);
    lStack_78 = 0;
    pppppplVar28 = pppppplVar19;
code_r0x06b4d894:
    uVar23 = uVar23 & 0xffff;
    iVar30 = (int)uVar23;
    pppppplVar32 = pppppplVar28 + uStack_40 * 3 + 0x2d;
    if (uStack_40 < uVar23) {
      ppppplStack_70 = (long *****)(uStack_40 + 1);
      iVar30 = iVar30 - (int)uStack_40;
      uStack_50 = uVar23;
      (*(code *)&DAT_120cba9a)
                (pppppplVar28 + (long)ppppplStack_70 * 3 + 0x2d,pppppplVar32,
                 (ulong)(uint)(iVar30 * 8) * 3);
      uVar6 = *(undefined4 *)((long)plStack_38 + 4);
      lVar31 = plStack_38[1];
      uVar7 = *(undefined4 *)((long)plStack_38 + 0xc);
      *(int *)pppppplVar32 = (int)*plStack_38;
      *(undefined4 *)((long)pppppplVar32 + 4) = uVar6;
      *(int *)(pppppplVar32 + 1) = (int)lVar31;
      *(undefined4 *)((long)pppppplVar32 + 0xc) = uVar7;
      pppppplVar32[2] = (long *****)plStack_38[2];
      (*(code *)&DAT_120cba9a)
                (pppppplVar28 + (long)ppppplStack_70 * 4,pppppplVar28 + uStack_40 * 4,iVar30 * 0x20)
      ;
      iVar30 = (int)uStack_50;
    }
    else {
      pppppplVar32[2] = (long *****)plStack_38[2];
      ppppplVar20 = (long *****)plStack_38[1];
      *pppppplVar32 = (long *****)*plStack_38;
      pppppplVar32[1] = ppppplVar20;
    }
    ppppplVar20 = (long *****)*ppppplStack_48;
    ppppplVar14 = (long *****)ppppplStack_48[1];
    ppppplVar4 = (long *****)ppppplStack_48[3];
    pppppplVar28[uStack_40 * 4 + 2] = (long *****)ppppplStack_48[2];
    (pppppplVar28 + uStack_40 * 4 + 2)[1] = ppppplVar4;
    pppppplVar28[uStack_40 * 4] = ppppplVar20;
    (pppppplVar28 + uStack_40 * 4)[1] = ppppplVar14;
    *(short *)((long)pppppplVar28 + 0x272) = (short)iVar30 + 1;
    if ((long *****)pppplStack_58 == (long *****)0xffffffffffffffff) {
code_r0x06b4def8:
      *plStack_68 = (long)pppppplVar28;
      plStack_68[1] = lStack_78;
      plStack_68[2] = uStack_40;
      return plStack_68;
    }
    uStack_108 = SUB84(uStack_138,0);
    uStack_104 = (undefined4)((ulong)uStack_138 >> 0x20);
    uStack_100 = SUB84(uStack_130,0);
    uStack_fc = (undefined4)((ulong)uStack_130 >> 0x20);
    uStack_d8 = uStack_108;
    uStack_d4 = uStack_104;
    uStack_d0 = uStack_100;
    uStack_cc = uStack_fc;
    pppppplVar32 = (long ******)pppppplVar25[0x2c];
    ppppplStack_90 = (long *****)pppppplVar28;
    if (pppppplVar32 == (long ******)0x0) {
      lStack_60 = 0;
    }
    else {
      bVar34 = lStack_60 == 0;
      do {
        if (!bVar34) goto code_r0x06b4e231;
        uVar2 = *(ushort *)(pppppplVar25 + 0x4e);
        plVar21 = (long *)(ulong)uVar2;
        uVar3 = *(ushort *)((long)pppppplVar32 + 0x272);
        uStack_50 = (ulong)uVar3;
        pppplStack_88 = pppplStack_58;
        ppppplStack_70 = (long *****)pppppplVar19;
        if (uStack_50 < 0xb) {
          iVar30 = uVar3 + 1;
          lVar31 = (long)plVar21 + 1;
          pppppplVar28 = pppppplVar32 + (long)plVar21 * 3 + 0x2d;
          if (uVar2 < uVar3) {
            lVar33 = uStack_50 - (long)plVar21;
            plStack_38 = (long *)(lVar33 * 8);
            ppppplStack_48 = (long *****)CONCAT44(ppppplStack_48._4_4_,iVar30);
            (*(code *)&DAT_120cba9a)(pppppplVar32 + lVar31 * 3 + 0x2d,pppppplVar28,lVar33 * 0x18);
            *pppppplVar28 = (long *****)pppplStack_88;
            *(undefined4 *)(pppppplVar28 + 1) = uStack_d8;
            *(undefined4 *)((long)pppppplVar28 + 0xc) = uStack_d4;
            *(undefined4 *)(pppppplVar28 + 2) = uStack_d0;
            *(undefined4 *)((long)pppppplVar28 + 0x14) = uStack_cc;
            uVar23 = (ulong)uVar2;
            (*(code *)&DAT_120cba9a)
                      ((ulong)((uint)lVar31 << 5) + (long)pppppplVar32,pppppplVar32 + uVar23 * 4,
                       lVar33 * 0x20);
            pppppplVar28 = pppppplVar32 + uVar23 * 4;
            *(undefined4 *)pppppplVar28 = uStack_128;
            *(undefined4 *)((long)pppppplVar28 + 4) = uStack_124;
            *(undefined4 *)(pppppplVar28 + 1) = uStack_120;
            *(undefined4 *)((long)pppppplVar28 + 0xc) = uStack_11c;
            pppppplVar28 = pppppplVar32 + uVar23 * 4 + 2;
            *(undefined4 *)pppppplVar28 = uStack_118;
            *(undefined4 *)((long)pppppplVar28 + 4) = uStack_114;
            *(undefined4 *)(pppppplVar28 + 1) = uStack_110;
            *(undefined4 *)((long)pppppplVar28 + 0xc) = uStack_10c;
            (*(code *)&DAT_120cba9a)
                      (pppppplVar32 + (long)plVar21 + 0x51,pppppplVar32 + (long)(plVar21 + 10),
                       plStack_38);
            pppppplVar19 = (long ******)ppppplStack_70;
            iVar30 = (int)ppppplStack_48;
          }
          else {
            *pppppplVar28 = (long *****)pppplStack_58;
            pppppplVar28[1] = (long *****)CONCAT44(uStack_d4,uStack_d8);
            pppppplVar28[2] = (long *****)CONCAT44(uStack_cc,uStack_d0);
            pppppplVar32[(ulong)uVar2 * 4] = (long *****)CONCAT44(uStack_124,uStack_128);
            (pppppplVar32 + (ulong)uVar2 * 4)[1] = (long *****)CONCAT44(uStack_11c,uStack_120);
            pppppplVar32[(ulong)uVar2 * 4 + 2] = (long *****)CONCAT44(uStack_114,uStack_118);
            (pppppplVar32 + (ulong)uVar2 * 4 + 2)[1] = (long *****)CONCAT44(uStack_10c,uStack_110);
          }
          pppppplVar32[(long)(plVar21 + 10)] = (long *****)pppppplVar19;
          *(short *)((long)pppppplVar32 + 0x272) = (short)iVar30;
          if ((uint)lVar31 < (uint)(uStack_50 + 2)) {
            uVar24 = ((int)uStack_50 - (uint)uVar2) + 1 & 3;
            if (uVar24 != 0) {
              uVar23 = 0;
              do {
                ppppplVar20 = pppppplVar32[(long)plVar21 + uVar23 + 0x50];
                ppppplVar20[0x2c] = (long ****)pppppplVar32;
                *(short *)(ppppplVar20 + 0x4e) = (short)lVar31 + (short)uVar23;
                uVar23 = uVar23 + 1;
              } while (uVar24 != uVar23);
              lVar31 = lVar31 + uVar23;
            }
            if (2 < (int)uStack_50 - (uint)uVar2) {
              do {
                ppppplVar20 = pppppplVar32[lVar31 + 0x4f];
                ppppplVar20[0x2c] = (long ****)pppppplVar32;
                sVar29 = (short)lVar31;
                *(short *)(ppppplVar20 + 0x4e) = sVar29;
                ppppplVar20 = pppppplVar32[lVar31 + 0x50];
                ppppplVar20[0x2c] = (long ****)pppppplVar32;
                *(short *)(ppppplVar20 + 0x4e) = sVar29 + 1;
                ppppplVar20 = pppppplVar32[lVar31 + 0x51];
                ppppplVar20[0x2c] = (long ****)pppppplVar32;
                *(short *)(ppppplVar20 + 0x4e) = sVar29 + 2;
                ppppplVar20 = pppppplVar32[lVar31 + 0x52];
                ppppplVar20[0x2c] = (long ****)pppppplVar32;
                *(short *)(ppppplVar20 + 0x4e) = sVar29 + 3;
                lVar31 = lVar31 + 4;
              } while (lVar31 != uStack_50 + 2);
            }
          }
          goto code_r0x06b4dfdd;
        }
        uVar23 = 4;
        plStack_38 = plVar21;
        if (uVar2 < 5) {
          pppppplVar28 = &ppppplStack_a0;
        }
        else if (plVar21 == (long *)0x5) {
          pppppplVar28 = &ppppplStack_a0;
          uVar23 = 5;
        }
        else if (uVar2 == 6) {
          uVar23 = 5;
          pppppplVar28 = &ppppplStack_98;
          plStack_38 = (long *)0x0;
        }
        else {
          uVar23 = 6;
          pppppplVar28 = &ppppplStack_98;
          plStack_38 = (long *)((long)plVar21 + -7);
        }
        (*(code *)&DAT_04732870)();
        pppppplVar19 = (long ******)(*(code *)&DAT_04732830)(0x2d8,8);
        if (pppppplVar19 == (long ******)0x0) goto code_r0x06b4e221;
        pppppplVar19[0x2c] = (long *****)0x0;
        *(undefined2 *)((long)pppppplVar19 + 0x272) = 0;
        uVar26 = ~uVar23 + (ulong)*(ushort *)((long)pppppplVar32 + 0x272);
        *(short *)((long)pppppplVar19 + 0x272) = (short)uVar26;
        pppplStack_58 = (long ****)pppppplVar32[uVar23 * 3 + 0x2d];
        ppppplVar20 = pppppplVar32[uVar23 * 3 + 0x2e];
        ppppplVar14 = (pppppplVar32 + uVar23 * 3 + 0x2e)[1];
        uVar22 = (ulong)(uint)((int)uVar23 << 5);
        puVar1 = (undefined4 *)((long)pppppplVar32 + uVar22);
        uVar6 = *puVar1;
        uVar7 = puVar1[1];
        uVar8 = puVar1[2];
        uVar9 = puVar1[3];
        puVar1 = (undefined4 *)((long)pppppplVar32 + uVar22 + 0x10);
        uVar10 = *puVar1;
        uVar11 = puVar1[1];
        uVar12 = puVar1[2];
        uVar13 = puVar1[3];
        if (0xb < uVar26) {
          (*(code *)&DAT_120a4440)(0,uVar26,0xb,&UNK_12135920);
          lVar31 = extraout_RDX;
code_r0x06b4e20a:
          (*(code *)&DAT_120a4440)(0,lVar31,0xc,&UNK_121346a8);
          goto code_r0x06b4e221;
        }
        ppppplStack_80 = (long *****)pppppplVar28;
        (*(code *)&DAT_120cba68)
                  (pppppplVar19 + 0x2d,pppppplVar32 + (uVar23 + 1) * 3 + 0x2d,uVar26 * 0x18);
        (*(code *)&DAT_120cba68)
                  (pppppplVar19,(ulong)(uint)((int)(uVar23 + 1) << 5) + (long)pppppplVar32,
                   uVar26 * 0x20);
        *(short *)((long)pppppplVar32 + 0x272) = (short)uVar23;
        uVar22 = (ulong)*(ushort *)((long)pppppplVar19 + 0x272);
        lVar31 = uVar22 + 1;
        pppppplVar28 = pppppplVar32;
        ppppplStack_48 = (long *****)pppppplVar32;
        if (0xb < uVar22) goto code_r0x06b4e20a;
        if ((int)uStack_50 - (int)uVar23 != (int)lVar31) goto code_r0x06b4e24a;
        lStack_60 = lStack_60 + 1;
        (*(code *)&DAT_120cba68)(pppppplVar19 + 0x4f,pppppplVar32 + uVar23 + 0x50,(int)lVar31 << 3);
        plVar21 = plStack_38;
        uVar23 = 0;
        do {
          uVar26 = uVar23 + (uVar23 < uVar22);
          ppppplVar4 = pppppplVar19[uVar23 + 0x4f];
          ppppplVar4[0x2c] = (long ****)pppppplVar19;
          *(short *)(ppppplVar4 + 0x4e) = (short)uVar23;
          if (uVar22 <= uVar23) break;
          uVar23 = uVar26;
        } while (uVar26 <= uVar22);
        ppppplStack_a0 = ppppplStack_48;
        uStack_138._4_4_ = (undefined4)((ulong)ppppplVar20 >> 0x20);
        uStack_130._4_4_ = (undefined4)((ulong)ppppplVar14 >> 0x20);
        uVar15 = SUB84(ppppplVar20,0);
        uVar16 = SUB84(ppppplVar14,0);
        pppppplVar28 = (long ******)*ppppplStack_80;
        uVar2 = *(ushort *)((long)pppppplVar28 + 0x272);
        plVar27 = (long *)(ulong)uVar2;
        lVar31 = (long)plStack_38 + 1;
        pppppplVar25 = pppppplVar28 + (long)plStack_38 * 3 + 0x2d;
        uVar23 = (long)plVar27 - (long)plStack_38;
        ppppplStack_98 = (long *****)pppppplVar19;
        if (plVar27 < plStack_38 || uVar23 == 0) {
          *pppppplVar25 = (long *****)pppplStack_88;
          pppppplVar25[1] = (long *****)CONCAT44(uStack_d4,uStack_d8);
          pppppplVar25[2] = (long *****)CONCAT44(uStack_cc,uStack_d0);
          pppppplVar28[(long)plStack_38 * 4 + 2] = (long *****)CONCAT44(uStack_114,uStack_118);
          (pppppplVar28 + (long)plStack_38 * 4 + 2)[1] = (long *****)CONCAT44(uStack_10c,uStack_110)
          ;
          pppppplVar28[(long)plStack_38 * 4] = (long *****)CONCAT44(uStack_124,uStack_128);
          (pppppplVar28 + (long)plStack_38 * 4)[1] = (long *****)CONCAT44(uStack_11c,uStack_120);
        }
        else {
          iVar30 = (uint)uVar2 - (int)plStack_38;
          ppppplStack_80 = (long *****)(ulong)(uint)(iVar30 * 8);
          uStack_50 = uVar23;
          (*(code *)&DAT_120cba9a)
                    (pppppplVar28 + lVar31 * 3 + 0x2d,pppppplVar25,(long)ppppplStack_80 * 3);
          plVar18 = plStack_38;
          *pppppplVar25 = (long *****)pppplStack_88;
          *(undefined4 *)(pppppplVar25 + 1) = uStack_d8;
          *(undefined4 *)((long)pppppplVar25 + 0xc) = uStack_d4;
          *(undefined4 *)(pppppplVar25 + 2) = uStack_d0;
          *(undefined4 *)((long)pppppplVar25 + 0x14) = uStack_cc;
          (*(code *)&DAT_120cba9a)
                    (pppppplVar28 + lVar31 * 4,pppppplVar28 + (long)plStack_38 * 4,iVar30 * 0x20);
          pppppplVar25 = pppppplVar28 + (long)plVar18 * 4;
          *(undefined4 *)pppppplVar25 = uStack_128;
          *(undefined4 *)((long)pppppplVar25 + 4) = uStack_124;
          *(undefined4 *)(pppppplVar25 + 1) = uStack_120;
          *(undefined4 *)((long)pppppplVar25 + 0xc) = uStack_11c;
          pppppplVar25 = pppppplVar28 + (long)plVar18 * 4 + 2;
          *(undefined4 *)pppppplVar25 = uStack_118;
          *(undefined4 *)((long)pppppplVar25 + 4) = uStack_114;
          *(undefined4 *)(pppppplVar25 + 1) = uStack_110;
          *(undefined4 *)((long)pppppplVar25 + 0xc) = uStack_10c;
          (*(code *)&DAT_120cba9a)
                    (pppppplVar28 + (long)plStack_38 + 0x51,pppppplVar28 + (long)(plVar21 + 10),
                     ppppplStack_80);
          uVar23 = uStack_50;
        }
        pppppplVar28[(long)(plStack_38 + 10)] = ppppplStack_70;
        *(ushort *)((long)pppppplVar28 + 0x272) = uVar2 + 1;
        if ((uint)lVar31 < (uint)((long)plVar27 + 2)) {
          uVar24 = ((uint)uVar2 - (int)plStack_38) + 1 & 3;
          if (uVar24 != 0) {
            uVar22 = 0;
            do {
              ppppplVar20 = pppppplVar28[(long)plStack_38 + uVar22 + 0x50];
              ppppplVar20[0x2c] = (long ****)pppppplVar28;
              *(short *)(ppppplVar20 + 0x4e) = (short)lVar31 + (short)uVar22;
              uVar22 = uVar22 + 1;
            } while (uVar24 != uVar22);
            lVar31 = lVar31 + uVar22;
          }
          if (2 < (uint)uVar23) {
            do {
              ppppplVar20 = pppppplVar28[lVar31 + 0x4f];
              ppppplVar20[0x2c] = (long ****)pppppplVar28;
              sVar29 = (short)lVar31;
              *(short *)(ppppplVar20 + 0x4e) = sVar29;
              ppppplVar20 = pppppplVar28[lVar31 + 0x50];
              ppppplVar20[0x2c] = (long ****)pppppplVar28;
              *(short *)(ppppplVar20 + 0x4e) = sVar29 + 1;
              ppppplVar20 = pppppplVar28[lVar31 + 0x51];
              ppppplVar20[0x2c] = (long ****)pppppplVar28;
              *(short *)(ppppplVar20 + 0x4e) = sVar29 + 2;
              ppppplVar20 = pppppplVar28[lVar31 + 0x52];
              ppppplVar20[0x2c] = (long ****)pppppplVar28;
              *(short *)(ppppplVar20 + 0x4e) = sVar29 + 3;
              lVar31 = lVar31 + 4;
            } while (lVar31 != (long)plVar27 + 2);
          }
        }
        if ((long *****)pppplStack_58 == (long *****)0xffffffffffffffff) goto code_r0x06b4dfdd;
        uStack_d4 = uStack_138._4_4_;
        uStack_cc = uStack_130._4_4_;
        pppppplVar32 = (long ******)ppppplStack_48[0x2c];
        bVar34 = true;
        pppppplVar25 = (long ******)ppppplStack_48;
        uStack_128 = uVar6;
        uStack_124 = uVar7;
        uStack_120 = uVar8;
        uStack_11c = uVar9;
        uStack_118 = uVar10;
        uStack_114 = uVar11;
        uStack_110 = uVar12;
        uStack_10c = uVar13;
        uStack_d8 = uVar15;
        uStack_d0 = uVar16;
      } while (pppppplVar32 != (long ******)0x0);
    }
    pppplVar17 = pppplStack_58;
    param_5 = (undefined8 *)*param_5;
    pppppplVar28 = (long ******)*param_5;
    if (pppppplVar28 == (long ******)0x0) goto code_r0x06b4e28a;
    lVar31 = param_5[1];
    (*(code *)&DAT_04732870)();
    ppppplVar20 = (long *****)(*(code *)&DAT_04732830)(0x2d8,8);
    if (ppppplVar20 == (long *****)0x0) {
code_r0x06b4e221:
      (*(code *)&DAT_12088f47)(8,0x2d8);
code_r0x06b4e231:
      pppppplVar32 = pppppplVar28;
      (*(code *)&DAT_1208f3b0)(&UNK_006cba64,0x35,&UNK_12134690);
code_r0x06b4e24a:
      (*(code *)&DAT_1208f3b0)(&UNK_006cc020,0x28,&UNK_12134780);
      goto code_r0x06b4e263;
    }
    ppppplVar20[0x2c] = (long ****)0x0;
    *(undefined2 *)((long)ppppplVar20 + 0x272) = 0;
    ppppplVar20[0x4f] = (long ****)pppppplVar28;
    lVar33 = lVar31 + 1;
    if (lVar33 != 0) {
      pppppplVar28[0x2c] = ppppplVar20;
      *(undefined2 *)(pppppplVar28 + 0x4e) = 0;
      *param_5 = ppppplVar20;
      param_5[1] = lVar33;
      if (lStack_60 == lVar31) {
        *(undefined2 *)((long)ppppplVar20 + 0x272) = 1;
        ppppplVar20[0x2d] = pppplVar17;
        ppppplVar20[0x2e] = (long ****)CONCAT44(uStack_d4,uStack_d8);
        ppppplVar20[0x2f] = (long ****)CONCAT44(uStack_cc,uStack_d0);
        *ppppplVar20 = (long ****)CONCAT44(uStack_124,uStack_128);
        ppppplVar20[1] = (long ****)CONCAT44(uStack_11c,uStack_120);
        ppppplVar20[2] = (long ****)CONCAT44(uStack_114,uStack_118);
        ppppplVar20[3] = (long ****)CONCAT44(uStack_10c,uStack_110);
        ppppplVar20[0x50] = (long ****)pppppplVar19;
        pppppplVar19[0x2c] = ppppplVar20;
        *(undefined2 *)(pppppplVar19 + 0x4e) = 1;
code_r0x06b4dfdd:
        *plStack_68 = (long)ppppplStack_90;
        plStack_68[1] = lStack_78;
        plStack_68[2] = uStack_40;
        return plStack_68;
      }
      goto code_r0x06b4e2a4;
    }
  }
  (*(code *)&DAT_120a4420)(&UNK_12134678);
code_r0x06b4e2a4:
  (*(code *)&DAT_1208f3b0)(&UNK_006cd605,0x30,&UNK_12135968);
  pcVar5 = (code *)swi(3);
  plVar21 = (long *)(*pcVar5)();
  return plVar21;
}

