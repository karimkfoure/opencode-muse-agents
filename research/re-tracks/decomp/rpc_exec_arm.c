
void rpc_exec_arm(char *param_1,int *param_2,long *param_3,byte *param_4,long param_5,
                 undefined8 *param_6,long param_7,undefined8 param_8,undefined4 *param_9)

{
  byte bVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  long *plVar9;
  long lVar10;
  ulong uVar11;
  undefined8 uVar12;
  ulong uVar13;
  undefined8 uVar14;
  long lVar15;
  int *piVar16;
  long *plVar17;
  long *plVar18;
  undefined8 *puStack_bf8;
  undefined *puStack_bf0;
  long lStack_740;
  undefined8 uStack_738;
  long lStack_730;
  undefined8 uStack_728;
  undefined4 uStack_720;
  undefined4 uStack_71c;
  undefined4 uStack_718;
  undefined4 uStack_714;
  undefined1 uStack_710;
  char cStack_708;
  byte bStack_707;
  undefined2 uStack_706;
  undefined2 uStack_704;
  undefined2 uStack_702;
  undefined2 uStack_700;
  undefined2 uStack_6fe;
  undefined2 uStack_6fc;
  undefined2 uStack_6fa;
  undefined2 uStack_6f8;
  undefined6 uStack_6f6;
  undefined2 uStack_6f0;
  undefined2 uStack_6ee;
  undefined4 uStack_6ec;
  undefined2 uStack_6e8;
  undefined2 uStack_6e6;
  undefined4 uStack_6e4;
  undefined2 uStack_6e0;
  undefined6 uStack_6de;
  undefined2 uStack_6d8;
  undefined6 uStack_6d6;
  undefined2 uStack_6d0;
  undefined6 uStack_6ce;
  undefined2 uStack_6c8;
  undefined6 uStack_6c6;
  undefined2 uStack_6c0;
  undefined6 uStack_6be;
  undefined1 uStack_6b8;
  byte bStack_6b7;
  undefined4 uStack_6b6;
  undefined2 uStack_6b2;
  undefined2 uStack_6b0;
  undefined6 uStack_6ae;
  undefined2 uStack_6a8;
  undefined6 uStack_6a6;
  undefined2 uStack_6a0;
  undefined2 uStack_69e;
  undefined4 uStack_69c;
  undefined2 uStack_698;
  undefined2 uStack_696;
  undefined4 uStack_694;
  long lStack_690;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  long lStack_208;
  undefined4 uStack_1f6;
  undefined2 uStack_1f2;
  undefined2 uStack_1f0;
  undefined2 uStack_1ee;
  undefined2 uStack_1ec;
  undefined2 uStack_1ea;
  undefined2 uStack_1e8;
  undefined2 uStack_1e6;
  undefined4 uStack_1e4;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  long lStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  long lStack_140;
  undefined1 uStack_138;
  undefined1 uStack_137;
  undefined4 uStack_136;
  undefined2 uStack_132;
  undefined8 uStack_130;
  ulong uStack_128;
  long lStack_120;
  undefined8 uStack_118;
  ulong uStack_110;
  undefined8 uStack_108;
  long *plStack_100;
  long lStack_f8;
  long lStack_f0;
  long lStack_e8;
  long lStack_e0;
  undefined8 uStack_d8;
  long lStack_d0;
  long lStack_c8;
  long lStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  long lStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  long lStack_78;
  long lStack_68;
  int *piStack_60;
  long lStack_58;
  long *plStack_50;
  long *plStack_48;
  undefined1 uStack_39;
  char *pcStack_38;
  
  bVar1 = *param_4;
  lStack_68 = param_5;
  piStack_60 = param_2;
  plStack_48 = param_3;
  pcStack_38 = param_1;
  if ((bVar1 ^ 1) == 0) {
    uStack_1d8 = *(long *)(param_4 + 1);
    uStack_1d0 = *(undefined4 *)(param_4 + 9);
    uStack_1cc = *(undefined4 *)(param_4 + 0xd);
  }
  else {
    uStack_1d8 = param_7;
    puStack_bf8 = &uStack_1d8;
    puStack_bf0 = &DAT_120a3e30;
    (*(code *)&DAT_12089060)(&cStack_708,&UNK_003242d7,&puStack_bf8);
    puStack_bf8 = (undefined8 *)*param_6;
    puStack_bf0 = (undefined *)param_6[1];
    uVar14 = CONCAT26(uStack_6fa,CONCAT24(uStack_6fc,CONCAT22(uStack_6fe,uStack_700)));
    (*(code *)&DAT_0fed3f80)(&uStack_1d8,&puStack_bf8,uVar14,CONCAT62(uStack_6f6,uStack_6f8));
    lVar10 = CONCAT26(uStack_702,
                      CONCAT24(uStack_704,CONCAT22(uStack_706,CONCAT11(bStack_707,cStack_708))));
    if (lVar10 != 0) {
      (*(code *)&DAT_04732840)(uVar14,lVar10,1);
    }
  }
  plVar17 = plStack_48;
  func_0x0c207420(&puStack_bf8,plStack_48);
  piVar16 = piStack_60;
  uStack_738 = CONCAT44(uStack_1cc,uStack_1d0);
  lStack_740 = uStack_1d8;
  lStack_730 = lStack_68;
  uStack_728 = param_8;
  uStack_720 = *param_9;
  uStack_71c = param_9[1];
  uStack_718 = param_9[2];
  uStack_714 = param_9[3];
  uStack_710 = *(undefined1 *)(param_9 + 4);
  if ((char)piStack_60[0x192] != '\0') {
    lVar10 = 0x24;
    if (2 < *plVar17) {
      lVar10 = *plVar17 + -3;
    }
    if ((0x36 < lVar10 - 0x18U) || ((0x40000000000003U >> (lVar10 - 0x18U & 0x3f) & 1) == 0)) {
      (*(code *)&DAT_120cba68)(&cStack_708,piStack_60,0x4f0);
      piVar16[0] = -2;
      piVar16[1] = -1;
      func_0x0d71e250(piVar16 + 0x146,&cStack_708);
      goto code_r0x0c179314;
    }
    (*(code *)&DAT_04732870)();
    puVar8 = (undefined4 *)(*(code *)&DAT_04732830)(0x2c,1);
    if (puVar8 == (undefined4 *)0x0) {
      (*(code *)&DAT_1208422d)(1,0x2c);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    *(undefined8 *)(puVar8 + 7) = 0x616e696d72657420;
    *(undefined8 *)(puVar8 + 9) = 0x64726f636572206c;
    *(undefined8 *)(puVar8 + 4) = 0x7265746661206174;
    *(undefined8 *)(puVar8 + 6) = 0x7265742073746920;
    *puVar8 = 0x61766e69;
    puVar8[1] = 0x2064696c;
    puVar8[2] = 0x6c696863;
    puVar8[3] = 0x61642064;
    pcStack_38[0] = '$';
    pcStack_38[1] = '\x01';
    pcStack_38[8] = ',';
    pcStack_38[9] = '\0';
    pcStack_38[10] = '\0';
    pcStack_38[0xb] = '\0';
    pcStack_38[0xc] = '\0';
    pcStack_38[0xd] = '\0';
    pcStack_38[0xe] = '\0';
    pcStack_38[0xf] = '\0';
    *(undefined4 **)(pcStack_38 + 0x10) = puVar8;
    pcStack_38[0x18] = ',';
    pcStack_38[0x19] = '\0';
    pcStack_38[0x1a] = '\0';
    pcStack_38[0x1b] = '\0';
    pcStack_38[0x1c] = '\0';
    pcStack_38[0x1d] = '\0';
    pcStack_38[0x1e] = '\0';
    pcStack_38[0x1f] = '\0';
    goto code_r0x0c179451;
  }
code_r0x0c179314:
  iVar6 = (int)*plVar17;
  iVar7 = iVar6;
  if (((*(long *)(piVar16 + 0x154) != -1) && (*(long *)(piVar16 + 0x160) != -1)) &&
     (*(char *)((long)piVar16 + 0x5a1) == '\x01')) {
    if (iVar6 == 0x51) {
      func_0x0b4491e0(piVar16 + 0x160,&uStack_39);
      iVar7 = (int)*plVar17;
    }
    else {
      *(undefined1 *)((long)piVar16 + 0x5a1) = 0;
    }
  }
  if (iVar7 == 0x1b) {
    (*(code *)&DAT_120cba68)(&cStack_708,&puStack_bf8,0x4f0);
    uStack_1d8 = plVar17[7];
    uStack_1d0 = (undefined4)plVar17[8];
    uStack_1cc = *(undefined4 *)((long)plVar17 + 0x44);
    func_0x0e33dc30(pcStack_38,piVar16,&cStack_708,&uStack_1d8,plVar17[2],plVar17[3]);
    goto code_r0x0c17945d;
  }
  func_0x0e33e870(&cStack_708,piVar16,plVar17,param_5 == 0 & (bVar1 ^ 1));
  if (cStack_708 == -1) {
    if ((bStack_707 & 1) == 0) {
      plVar18 = (long *)(piVar16 + 0x154);
      if (iVar6 == 0x51) {
        lVar10 = *(long *)(piVar16 + 0x154);
        if ((lVar10 == -1) || (*(long *)(piVar16 + 0x160) != -1)) {
          *(undefined1 *)(piVar16 + 0x192) = 1;
          lStack_78 = *(long *)(piVar16 + 0x172);
          uStack_88 = *(undefined8 *)(piVar16 + 0x16e);
          uStack_80 = *(undefined8 *)(piVar16 + 0x170);
          uStack_98 = *(undefined8 *)(piVar16 + 0x16a);
          uStack_90 = *(undefined8 *)(piVar16 + 0x16c);
          lStack_a8 = *(long *)(piVar16 + 0x166);
          uStack_a0 = *(ulong *)(piVar16 + 0x168);
          lStack_e8 = *(long *)(piVar16 + 0x156);
          lStack_e0 = *(long *)(piVar16 + 0x158);
          uStack_d8 = *(undefined8 *)(piVar16 + 0x15a);
          lStack_d0 = *(long *)(piVar16 + 0x15c);
          lStack_c8 = *(long *)(piVar16 + 0x15e);
          lStack_c0 = *(long *)(piVar16 + 0x160);
          uStack_b8 = *(undefined8 *)(piVar16 + 0x162);
          uStack_b0 = *(undefined8 *)(piVar16 + 0x164);
          piVar16[0x154] = -1;
          piVar16[0x155] = -1;
          if (lVar10 == -1) {
            if (*piVar16 != -2) {
              func_0x0bf9d510(piVar16);
            }
            (*(code *)&DAT_120cba68)(piVar16,&puStack_bf8,0x4f0);
            goto code_r0x0c179bf7;
          }
        }
        else {
          cVar5 = func_0x0c0db240(plVar18,(char)piVar16[0x193]);
          if (cVar5 == '\0') {
            uVar14 = *(undefined8 *)(piVar16 + 0x158);
            cStack_708 = '\x05';
            bStack_707 = 0;
            uStack_706 = 0;
            uStack_704 = 0;
            uStack_702 = 0x8000;
            uStack_700 = (undefined2)uVar14;
            uStack_6fe = (undefined2)((ulong)uVar14 >> 0x10);
            uStack_6fc = (undefined2)((ulong)uVar14 >> 0x20);
            uStack_6fa = (undefined2)((ulong)uVar14 >> 0x30);
            func_0x0c1faf10(&uStack_1d8,&cStack_708);
            plVar17 = plStack_48;
            uStack_1e0 = CONCAT44(uStack_1c4,uStack_1c8);
            uStack_1f0 = (undefined2)uStack_1d8;
            uStack_1ee = (undefined2)((ulong)uStack_1d8 >> 0x10);
            uStack_1ec = (undefined2)((ulong)uStack_1d8 >> 0x20);
            uStack_1ea = (undefined2)((ulong)uStack_1d8 >> 0x30);
            uStack_1e8 = (undefined2)uStack_1d0;
            uStack_1e6 = (undefined2)((uint)uStack_1d0 >> 0x10);
            uStack_1e4 = uStack_1cc;
            func_0x0bfa7b20(&cStack_708);
            pcStack_38[0] = '$';
            pcStack_38[1] = '\x01';
            *(undefined4 *)(pcStack_38 + 2) = uStack_1f6;
            *(uint *)(pcStack_38 + 6) = CONCAT22(uStack_1f0,uStack_1f2);
            *(uint *)(pcStack_38 + 10) = CONCAT22(uStack_1ec,uStack_1ee);
            *(uint *)(pcStack_38 + 0xe) = CONCAT22(uStack_1e8,uStack_1ea);
            *(ulong *)(pcStack_38 + 0x10) = CONCAT44(uStack_1e4,CONCAT22(uStack_1e6,uStack_1e8));
            *(undefined8 *)(pcStack_38 + 0x18) = uStack_1e0;
            goto code_r0x0c179451;
          }
          *(undefined1 *)(piVar16 + 0x192) = 1;
          lStack_78 = *(long *)(piVar16 + 0x172);
          uStack_88 = *(undefined8 *)(piVar16 + 0x16e);
          uStack_80 = *(undefined8 *)(piVar16 + 0x170);
          uStack_98 = *(undefined8 *)(piVar16 + 0x16a);
          uStack_90 = *(undefined8 *)(piVar16 + 0x16c);
          lStack_a8 = *(long *)(piVar16 + 0x166);
          uStack_a0 = *(ulong *)(piVar16 + 0x168);
          lStack_e8 = *(long *)(piVar16 + 0x156);
          lStack_e0 = *(long *)(piVar16 + 0x158);
          uStack_d8 = *(undefined8 *)(piVar16 + 0x15a);
          lStack_d0 = *(long *)(piVar16 + 0x15c);
          lStack_c8 = *(long *)(piVar16 + 0x15e);
          lStack_c0 = *(long *)(piVar16 + 0x160);
          uStack_b8 = *(undefined8 *)(piVar16 + 0x162);
          uStack_b0 = *(undefined8 *)(piVar16 + 0x164);
          piVar16[0x154] = -1;
          piVar16[0x155] = -1;
        }
code_r0x0c17967e:
        cStack_708 = (char)lVar10;
        bStack_707 = (byte)((ulong)lVar10 >> 8);
        uStack_706 = (undefined2)((ulong)lVar10 >> 0x10);
        uStack_704 = (undefined2)((ulong)lVar10 >> 0x20);
        uStack_702 = (undefined2)((ulong)lVar10 >> 0x30);
        uStack_700 = (undefined2)lStack_e8;
        uStack_6fe = (undefined2)((ulong)lStack_e8 >> 0x10);
        uStack_6fc = (undefined2)((ulong)lStack_e8 >> 0x20);
        uStack_6fa = (undefined2)((ulong)lStack_e8 >> 0x30);
        uStack_6f8 = (undefined2)lStack_e0;
        uStack_6f6 = (undefined6)((ulong)lStack_e0 >> 0x10);
        uStack_6f0 = (undefined2)uStack_d8;
        uStack_6ee = (undefined2)((ulong)uStack_d8 >> 0x10);
        uStack_6ec = (undefined4)((ulong)uStack_d8 >> 0x20);
        uStack_6e8 = (undefined2)lStack_d0;
        uStack_6e6 = (undefined2)((ulong)lStack_d0 >> 0x10);
        uStack_6e4 = (undefined4)((ulong)lStack_d0 >> 0x20);
        uStack_6d0 = (undefined2)uStack_b8;
        uStack_6ce = (undefined6)((ulong)uStack_b8 >> 0x10);
        uStack_6c8 = (undefined2)uStack_b0;
        uStack_6c6 = (undefined6)((ulong)uStack_b0 >> 0x10);
        uStack_6c0 = (undefined2)lStack_a8;
        uStack_6be = (undefined6)((ulong)lStack_a8 >> 0x10);
        uStack_6b8 = (undefined1)uStack_a0;
        bStack_6b7 = (byte)(uStack_a0 >> 8);
        uStack_6b6 = (undefined4)(uStack_a0 >> 0x10);
        uStack_6b2 = (undefined2)(uStack_a0 >> 0x30);
        uStack_6b0 = (undefined2)uStack_98;
        uStack_6ae = (undefined6)((ulong)uStack_98 >> 0x10);
        uStack_6a8 = (undefined2)uStack_90;
        uStack_6a6 = (undefined6)((ulong)uStack_90 >> 0x10);
        uStack_6a0 = (undefined2)uStack_88;
        uStack_69e = (undefined2)((ulong)uStack_88 >> 0x10);
        uStack_69c = uStack_88._4_4_;
        uStack_698 = (undefined2)uStack_80;
        uStack_696 = (undefined2)((ulong)uStack_80 >> 0x10);
        uStack_694 = uStack_80._4_4_;
        lStack_690 = lStack_78;
        uStack_6e0 = (undefined2)lStack_c8;
        uStack_6de = (undefined6)((ulong)lStack_c8 >> 0x10);
        uVar11 = uStack_a0 & 0xff;
        uVar13 = (ulong)bStack_6b7;
        uStack_6d8 = 0xffff;
        uStack_6d6 = 0xffffffffffff;
        lVar10 = lStack_c0;
        uVar14 = uStack_b8;
        uVar12 = uStack_b0;
        lVar15 = lStack_a8;
        uVar4 = uStack_a0;
        if (lStack_c0 == -1) {
          lVar10 = -1;
          if ((((char)piVar16[0x193] == '\0') && (lStack_e0 != 0)) && (lStack_c8 != 0)) {
            lStack_f8 = lStack_e0 * 0x60 + lStack_e8;
            plVar17 = (long *)(lStack_c8 * 0x4f0 + lStack_d0);
            plStack_100 = (long *)(lStack_d0 + 0x38);
            lVar10 = lStack_e8;
            uStack_128 = uVar11;
            lStack_120 = lStack_a8;
            uStack_118 = uStack_b0;
            uStack_110 = uVar13;
            uStack_108 = uStack_b8;
            lStack_f0 = lStack_c8;
            plStack_50 = plVar18;
            do {
              uStack_130 = *(undefined8 *)(lVar10 + 0x20);
              lStack_58 = *(long *)(lVar10 + 0x28);
              lVar10 = lVar10 + 0x60;
              plVar18 = plStack_100;
              while (((((int)plVar18[-7] != 0x1c || (plVar18[-4] != lStack_58)) ||
                      (iVar7 = (*(code *)&DAT_120cae9d)(plVar18[-5],uStack_130,lStack_58),
                      iVar7 != 0)) ||
                     (((plVar18[-2] == 0xd3 &&
                       (lVar15 = *plVar18,
                       iVar7 = (*(code *)&DAT_120cae9d)(plVar18[-3] + 0x10,&UNK_011930ff,0xd3),
                       piVar16 = piStack_60, lVar15 == 0)) && (iVar7 == 0))))) {
                plVar9 = plVar18 + 0x97;
                plVar18 = plVar18 + 0x9e;
                if (plVar9 == plVar17) {
                  lVar10 = -1;
                  uVar11 = uStack_128;
                  lVar15 = lStack_120;
                  uVar12 = uStack_118;
                  uVar13 = uStack_110;
                  uVar14 = uStack_108;
                  plVar18 = plStack_50;
                  plVar17 = plStack_48;
                  goto code_r0x0c179a29;
                }
              }
            } while (lVar10 != lStack_f8);
            uVar11 = 0;
            uVar13 = 0;
            plVar18 = plStack_50;
            lVar10 = 0;
            uVar14 = 8;
            uVar12 = 0;
            lVar15 = lStack_f0;
            uVar4 = uStack_a0;
            plVar17 = plStack_48;
            goto joined_r0x0c179743;
          }
        }
        else {
joined_r0x0c179743:
          uStack_a0 = uVar4;
          if ((lStack_68 != 0) && (iVar6 != 0x51)) {
            uStack_138 = (undefined1)uVar11;
            uStack_137 = (undefined1)uVar13;
            uStack_a0._2_4_ = (undefined4)(uVar4 >> 0x10);
            uStack_136 = uStack_a0._2_4_;
            uStack_a0._6_2_ = (undefined2)(uVar4 >> 0x30);
            uStack_132 = uStack_a0._6_2_;
            lVar3 = CONCAT62(uStack_6de,uStack_6e0);
            lStack_158 = lVar10;
            uStack_150 = uVar14;
            uStack_148 = uVar12;
            lStack_140 = lVar15;
            if (lVar3 == CONCAT44(uStack_6ec,CONCAT22(uStack_6ee,uStack_6f0))) {
              (*(code *)&DAT_0c130f40)(&uStack_6f0);
            }
            (*(code *)&DAT_120cba68)
                      (lVar3 * 0x4f0 + CONCAT44(uStack_6e4,CONCAT22(uStack_6e6,uStack_6e8)),
                       &puStack_bf8,0x4f0);
            lStack_208 = lVar3 + 1;
            uStack_6e0 = (undefined2)lStack_208;
            uStack_6de = (undefined6)((ulong)lStack_208 >> 0x10);
            uStack_218 = CONCAT22(uStack_6ee,uStack_6f0);
            uStack_210 = CONCAT22(uStack_6e6,uStack_6e8);
            uStack_214 = uStack_6ec;
            uStack_20c = uStack_6e4;
            func_0x0c554070(&uStack_1d8,piVar16,
                            CONCAT26(uStack_6fa,CONCAT24(uStack_6fc,CONCAT22(uStack_6fe,uStack_700))
                                    ),CONCAT62(uStack_6f6,uStack_6f8),&uStack_218,&lStack_158,0);
            if ((char)uStack_1d8 != -1) {
              *(undefined8 *)(pcStack_38 + 0x70) = uStack_168;
              *(undefined8 *)(pcStack_38 + 0x60) = uStack_178;
              *(undefined8 *)(pcStack_38 + 0x68) = uStack_170;
              *(undefined8 *)(pcStack_38 + 0x50) = uStack_188;
              *(undefined8 *)(pcStack_38 + 0x58) = uStack_180;
              *(undefined8 *)(pcStack_38 + 0x40) = uStack_198;
              *(undefined8 *)(pcStack_38 + 0x48) = uStack_190;
              *(undefined4 *)(pcStack_38 + 0x30) = uStack_1a8;
              *(undefined4 *)(pcStack_38 + 0x34) = uStack_1a4;
              *(undefined4 *)(pcStack_38 + 0x38) = uStack_1a0;
              *(undefined4 *)(pcStack_38 + 0x3c) = uStack_19c;
              *(undefined4 *)(pcStack_38 + 0x20) = uStack_1b8;
              *(undefined4 *)(pcStack_38 + 0x24) = uStack_1b4;
              *(undefined4 *)(pcStack_38 + 0x28) = uStack_1b0;
              *(undefined4 *)(pcStack_38 + 0x2c) = uStack_1ac;
              *(undefined4 *)(pcStack_38 + 0x10) = uStack_1c8;
              *(undefined4 *)(pcStack_38 + 0x14) = uStack_1c4;
              *(undefined4 *)(pcStack_38 + 0x18) = uStack_1c0;
              *(undefined4 *)(pcStack_38 + 0x1c) = uStack_1bc;
              *(undefined4 *)pcStack_38 = (undefined4)uStack_1d8;
              *(undefined4 *)(pcStack_38 + 4) = uStack_1d8._4_4_;
              *(undefined4 *)(pcStack_38 + 8) = uStack_1d0;
              *(undefined4 *)(pcStack_38 + 0xc) = uStack_1cc;
              func_0x0bf988e0(&cStack_708);
              func_0x0d696f20(&uStack_6a0);
              func_0x0bf96c80(&uStack_6d8);
              goto code_r0x0c17945d;
            }
            func_0x0bf988e0(&cStack_708);
            func_0x0d696f20(&uStack_6a0);
            func_0x0bf96c80(&uStack_6d8);
            goto code_r0x0c179bf7;
          }
        }
code_r0x0c179a29:
        uStack_6d8 = (undefined2)lVar10;
        uStack_6d6 = (undefined6)((ulong)lVar10 >> 0x10);
        uStack_6d0 = (undefined2)uVar14;
        uStack_6ce = (undefined6)((ulong)uVar14 >> 0x10);
        uStack_6c8 = (undefined2)uVar12;
        uStack_6c6 = (undefined6)((ulong)uVar12 >> 0x10);
        uStack_6c0 = (undefined2)lVar15;
        uStack_6be = (undefined6)((ulong)lVar15 >> 0x10);
        uStack_6b8 = (undefined1)uVar11;
        bStack_6b7 = (byte)uVar13;
        uStack_6b2 = uStack_a0._6_2_;
        uStack_6b6 = uStack_a0._2_4_;
        lVar10 = CONCAT62(uStack_6de,uStack_6e0);
        if (lVar10 == CONCAT44(uStack_6ec,CONCAT22(uStack_6ee,uStack_6f0))) {
          (*(code *)&DAT_0c130f40)(&uStack_6f0);
        }
        (*(code *)&DAT_120cba68)
                  (lVar10 * 0x4f0 + CONCAT44(uStack_6e4,CONCAT22(uStack_6e6,uStack_6e8)),
                   &puStack_bf8,0x4f0);
        uStack_6e0 = (undefined2)(lVar10 + 1);
        uStack_6de = (undefined6)((ulong)(lVar10 + 1) >> 0x10);
        if (*plVar18 != -1) {
          func_0x0b6aa450(plVar18);
          if (*plVar18 != 0) {
            (*(code *)&DAT_04732840)(*(undefined8 *)(piVar16 + 0x156),*plVar18 * 0x60,8);
          }
          lVar10 = *(long *)(piVar16 + 0x15e);
          if (lVar10 != 0) {
            lVar15 = *(long *)(piVar16 + 0x15c);
            do {
              func_0x0b469860(lVar15);
              lVar15 = lVar15 + 0x4f0;
              lVar10 = lVar10 + -1;
            } while (lVar10 != 0);
          }
          if (*(long *)(piVar16 + 0x15a) != 0) {
            (*(code *)&DAT_04732840)
                      (*(undefined8 *)(piVar16 + 0x15c),*(long *)(piVar16 + 0x15a) * 0x4f0,8);
          }
          func_0x0d696f20(piVar16 + 0x16e);
          lVar10 = *(long *)(piVar16 + 0x160);
          if (lVar10 != -1) {
            lVar15 = *(long *)(piVar16 + 0x164);
            if (lVar15 != 0) {
              lVar10 = *(long *)(piVar16 + 0x162);
              do {
                func_0x0b469860(lVar10);
                lVar10 = lVar10 + 0x4f0;
                lVar15 = lVar15 + -1;
              } while (lVar15 != 0);
              lVar10 = *(long *)(piVar16 + 0x160);
            }
            if (lVar10 != 0) {
              (*(code *)&DAT_04732840)(*(undefined8 *)(piVar16 + 0x162),lVar10 * 0x4f0,8);
            }
          }
        }
        plVar18[0xe] = CONCAT44(uStack_694,CONCAT22(uStack_696,uStack_698));
        plVar18[0xf] = lStack_690;
        plVar18[0xc] = CONCAT62(uStack_6a6,uStack_6a8);
        plVar18[0xd] = CONCAT44(uStack_69c,CONCAT22(uStack_69e,uStack_6a0));
        plVar18[10] = CONCAT26(uStack_6b2,CONCAT42(uStack_6b6,CONCAT11(bStack_6b7,uStack_6b8)));
        plVar18[0xb] = CONCAT62(uStack_6ae,uStack_6b0);
        plVar18[8] = CONCAT62(uStack_6c6,uStack_6c8);
        plVar18[9] = CONCAT62(uStack_6be,uStack_6c0);
        plVar18[6] = CONCAT62(uStack_6d6,uStack_6d8);
        plVar18[7] = CONCAT62(uStack_6ce,uStack_6d0);
        plVar18[4] = CONCAT44(uStack_6e4,CONCAT22(uStack_6e6,uStack_6e8));
        plVar18[5] = CONCAT62(uStack_6de,uStack_6e0);
        plVar18[2] = CONCAT62(uStack_6f6,uStack_6f8);
        plVar18[3] = CONCAT44(uStack_6ec,CONCAT22(uStack_6ee,uStack_6f0));
        *(int *)plVar18 = CONCAT22(uStack_706,CONCAT11(bStack_707,cStack_708));
        *(int *)((long)plVar18 + 4) = CONCAT22(uStack_702,uStack_704);
        *(int *)(plVar18 + 1) = CONCAT22(uStack_6fe,uStack_700);
        *(int *)((long)plVar18 + 0xc) = CONCAT22(uStack_6fa,uStack_6fc);
      }
      else {
        lVar10 = *(long *)(piVar16 + 0x154);
        lStack_78 = *(long *)(piVar16 + 0x172);
        uStack_88 = *(undefined8 *)(piVar16 + 0x16e);
        uStack_80 = *(undefined8 *)(piVar16 + 0x170);
        uStack_98 = *(undefined8 *)(piVar16 + 0x16a);
        uStack_90 = *(undefined8 *)(piVar16 + 0x16c);
        lStack_a8 = *(long *)(piVar16 + 0x166);
        uStack_a0 = *(ulong *)(piVar16 + 0x168);
        uStack_b8 = *(undefined8 *)(piVar16 + 0x162);
        uStack_b0 = *(undefined8 *)(piVar16 + 0x164);
        lStack_c8 = *(long *)(piVar16 + 0x15e);
        lStack_c0 = *(long *)(piVar16 + 0x160);
        uStack_d8 = *(undefined8 *)(piVar16 + 0x15a);
        lStack_d0 = *(long *)(piVar16 + 0x15c);
        lStack_e8 = *(long *)(piVar16 + 0x156);
        lStack_e0 = *(long *)(piVar16 + 0x158);
        piVar16[0x154] = -1;
        piVar16[0x155] = -1;
        if (lVar10 != -1) goto code_r0x0c17967e;
        func_0x0d615a80(piVar16 + 0x146,&puStack_bf8);
      }
code_r0x0c179bf7:
      *pcStack_38 = -1;
      goto code_r0x0c17945d;
    }
    *pcStack_38 = -1;
  }
  else {
    *(ulong *)(pcStack_38 + 0x70) = CONCAT44(uStack_694,CONCAT22(uStack_696,uStack_698));
    *(ulong *)(pcStack_38 + 0x62) = CONCAT26(uStack_6a0,uStack_6a6);
    *(ulong *)(pcStack_38 + 0x6a) = CONCAT26(uStack_698,CONCAT42(uStack_69c,uStack_69e));
    *(ulong *)(pcStack_38 + 0x52) = CONCAT26(uStack_6b0,CONCAT24(uStack_6b2,uStack_6b6));
    *(ulong *)(pcStack_38 + 0x5a) = CONCAT26(uStack_6a8,uStack_6ae);
    *(ulong *)(pcStack_38 + 0x42) = CONCAT26(uStack_6c0,uStack_6c6);
    *(ulong *)(pcStack_38 + 0x4a) = CONCAT17(bStack_6b7,CONCAT16(uStack_6b8,uStack_6be));
    *(ulong *)(pcStack_38 + 0x32) = CONCAT26(uStack_6d0,uStack_6d6);
    *(ulong *)(pcStack_38 + 0x3a) = CONCAT26(uStack_6c8,uStack_6ce);
    *(ulong *)(pcStack_38 + 0x22) = CONCAT26(uStack_6e0,CONCAT42(uStack_6e4,uStack_6e6));
    *(ulong *)(pcStack_38 + 0x2a) = CONCAT26(uStack_6d8,uStack_6de);
    *(ulong *)(pcStack_38 + 0x12) = CONCAT26(uStack_6f0,uStack_6f6);
    *(ulong *)(pcStack_38 + 0x1a) = CONCAT26(uStack_6e8,CONCAT42(uStack_6ec,uStack_6ee));
    *(uint *)(pcStack_38 + 2) = CONCAT22(uStack_704,uStack_706);
    *(uint *)(pcStack_38 + 6) = CONCAT22(uStack_700,uStack_702);
    *(uint *)(pcStack_38 + 10) = CONCAT22(uStack_6fc,uStack_6fe);
    *(uint *)(pcStack_38 + 0xe) = CONCAT22(uStack_6f8,uStack_6fa);
    *pcStack_38 = cStack_708;
    pcStack_38[1] = bStack_707;
  }
code_r0x0c179451:
  func_0x0bf9d510(&puStack_bf8);
code_r0x0c17945d:
  func_0x0bf9d510(plVar17);
  return;
}

