
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * agent_rpc_router(undefined8 *param_1,long *****param_2,long *param_3)

{
  ushort *puVar1;
  long lVar2;
  long **pplVar3;
  long lVar4;
  long lVar5;
  long ***ppplVar6;
  long ***ppplVar7;
  code *pcVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined8 uVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  undefined8 *puVar15;
  undefined1 (*pauVar16) [16];
  long *plVar17;
  long *****ppppplVar18;
  long *plVar19;
  long *plVar20;
  long ****pppplVar21;
  long lVar22;
  long ****pppplVar23;
  undefined *puVar24;
  ulong uVar25;
  long *plVar26;
  ulong uVar27;
  ulong uVar28;
  ulong *puVar29;
  long *****ppppplVar30;
  long ****pppplVar31;
  long *****ppppplVar32;
  long *****ppppplVar33;
  long ****pppplVar34;
  undefined1 auVar35 [16];
  char cStack_758;
  undefined5 uStack_757;
  undefined2 uStack_752;
  undefined6 uStack_750;
  undefined2 uStack_74a;
  undefined6 uStack_748;
  undefined2 uStack_742;
  undefined6 uStack_740;
  undefined2 uStack_73a;
  undefined8 uStack_738;
  undefined8 uStack_730;
  undefined8 uStack_728;
  undefined8 uStack_720;
  long ***ppplStack_718;
  undefined8 uStack_710;
  long **pplStack_298;
  long **pplStack_290;
  long ***ppplStack_288;
  long ***ppplStack_280;
  long lStack_278;
  long lStack_270;
  long lStack_268;
  long lStack_260;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  ulong *puStack_238;
  long ****pppplStack_228;
  long ****pppplStack_220;
  undefined1 uStack_218;
  long ***ppplStack_208;
  long ****pppplStack_200;
  long ***ppplStack_1f8;
  undefined1 uStack_1e9;
  undefined7 uStack_1e8;
  undefined1 uStack_1e1;
  undefined7 uStack_1e0;
  undefined1 uStack_1d9;
  long ***ppplStack_1d8;
  long ***ppplStack_1d0;
  long ***ppplStack_1c8;
  long ****pppplStack_1c0;
  long ****pppplStack_1b8;
  long ***ppplStack_1b0;
  char cStack_1a8;
  undefined5 uStack_1a7;
  undefined2 uStack_1a2;
  undefined6 uStack_1a0;
  undefined2 uStack_19a;
  undefined6 uStack_198;
  undefined2 uStack_192;
  undefined6 uStack_190;
  undefined2 uStack_18a;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  long ***ppplStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  ulong *puStack_130;
  long ****pppplStack_128;
  long lStack_120;
  long ****pppplStack_118;
  long ****pppplStack_110;
  long ****pppplStack_108;
  long ****pppplStack_100;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  long ***ppplStack_e0;
  long ****pppplStack_d8;
  long ***ppplStack_d0;
  long ****pppplStack_c8;
  long *plStack_c0;
  long ****pppplStack_b8;
  long ***ppplStack_b0;
  uint uStack_9c;
  long ****pppplStack_98;
  long ****pppplStack_90;
  long ****pppplStack_88;
  long ****pppplStack_80;
  ulong uStack_78;
  long ***ppplStack_68;
  long ***ppplStack_60;
  long ****pppplStack_58;
  long ****pppplStack_50;
  undefined8 *puStack_48;
  long ****pppplStack_40;
  undefined1 uStack_31;
  
  ppppplVar18 = (long *****)param_3[0xe];
  ppppplVar30 = (long *****)param_3[0x11];
  uStack_218 = (undefined1)param_3[0x14];
  pppplStack_228 = (long ****)param_3[0x12];
  pppplStack_220 = (long ****)param_3[0x13];
  lStack_278 = param_3[5];
  lStack_270 = param_3[6];
  lStack_268 = param_3[7];
  lStack_260 = param_3[8];
  uStack_258 = (undefined4)param_3[9];
  uStack_254 = *(undefined4 *)((long)param_3 + 0x4c);
  uStack_250 = (undefined4)param_3[10];
  uStack_24c = *(undefined4 *)((long)param_3 + 0x54);
  uStack_248 = (undefined4)param_3[0xb];
  uStack_244 = *(undefined4 *)((long)param_3 + 0x5c);
  uStack_240 = (undefined4)param_3[0xc];
  uStack_23c = *(undefined4 *)((long)param_3 + 100);
  lVar22 = param_3[0xc];
  puVar29 = (ulong *)param_3[0xd];
  puStack_238 = puVar29;
  if ((char)lStack_278 == '\x1e') {
    uStack_258._3_1_ = (undefined1)((uint)uStack_258 >> 0x18);
    auVar9._1_4_ = uStack_254;
    auVar9[0] = uStack_258._3_1_;
    auVar9._5_4_ = uStack_250;
    auVar9._9_4_ = uStack_24c;
    auVar9._13_3_ = (undefined3)uStack_248;
    if (*(undefined1 (*) [16])(param_2 + 199) == auVar9) {
      pppplStack_b8 = (long ****)(param_3 + 0xf);
      *(undefined1 *)((long)param_2 + 0x649) = 1;
      uVar25 = 1;
      if ((long)*puVar29 < 0) {
        uVar25 = *puVar29 ^ 0x8000000000000000;
      }
      plStack_c0 = param_3;
      if (uVar25 == 0) {
        pppplStack_90 = (long ****)(param_3 + 0x12);
        pppplStack_50 = (long ****)((long)param_3 + 0x29);
        uVar25 = puVar29[1];
        pppplStack_98 = (long ****)ppppplVar30;
        pppplStack_58 = (long ****)ppppplVar18;
        (*(code *)&DAT_120cba68)(&cStack_758,uVar25,0x4b8);
        func_0x0c179120(param_1,param_2,&cStack_758,pppplStack_50,lVar22,pppplStack_b8,pppplStack_58
                        ,pppplStack_98,pppplStack_90);
        (*(code *)&DAT_04732840)(uVar25,0x4b8,8);
      }
      else {
        puStack_130 = puVar29;
        if (uVar25 == 1) {
          pppplStack_118 = (long ****)*puVar29;
          pppplStack_110 = (long ****)puVar29[1];
          pppplStack_108 = (long ****)puVar29[2];
          pppplStack_100 = (long ****)puVar29[3];
          uStack_f8 = (undefined4)puVar29[4];
          uStack_f4 = *(undefined4 *)((long)puVar29 + 0x24);
          uStack_f0 = (undefined4)puVar29[5];
          uStack_ec = *(undefined4 *)((long)puVar29 + 0x2c);
          if (*(char *)(param_2 + 0xc9) == '\0') {
            if (param_2[0xaa] == (long ****)0xffffffffffffffff) {
              (*(code *)&DAT_120846f0)(&uStack_750,&pppplStack_118);
              cStack_758 = '\0';
              uStack_757 = 0;
              uStack_752 = 0x8000;
              pppplStack_88 = (long ****)0x0;
              pppplStack_80 = (long ****)0x1;
              uStack_78 = 0;
              uStack_198 = 0x60000020;
              uStack_192 = 0;
              cStack_1a8 = (char)&pppplStack_88;
              uStack_1a7 = (undefined5)((ulong)&pppplStack_88 >> 8);
              uStack_1a2 = (undefined2)((ulong)&pppplStack_88 >> 0x30);
              uStack_1a0 = 0x1220fe88;
              uStack_19a = 0;
              cVar12 = (*(code *)&DAT_0c7cdef0)(&cStack_758,&cStack_1a8);
              pppplVar23 = pppplStack_88;
              if (cVar12 != '\0') goto code_r0x0c178d5f;
              param_1[2] = pppplStack_80;
              param_1[3] = uStack_78;
              func_0x0bfa7b20(&cStack_758);
              *(undefined2 *)param_1 = 0x124;
              param_1[1] = pppplVar23;
            }
            else if (param_2[0xb0] == (long ****)0xffffffffffffffff) {
              pppplStack_90 = (long ****)(param_2 + 199);
              if (*(char *)((long)param_2 + 0x64c) == '\0') {
                pppplVar23 = (long ****)*pppplStack_90;
                cStack_758 = (char)pppplVar23;
                uStack_757 = (undefined5)((ulong)pppplVar23 >> 8);
                uStack_752 = (undefined2)((ulong)pppplVar23 >> 0x30);
                uStack_750 = SUB86(param_2[200],0);
                uStack_74a = (undefined2)((ulong)param_2[200] >> 0x30);
                pppplStack_98 = (long ****)ppppplVar30;
                uVar13 = (*(code *)&DAT_0d237a60)(pppplStack_110,pppplStack_108,&cStack_758);
                if (*(char *)((long)param_2 + 0x64c) != '\0') goto code_r0x0c177f9b;
              }
              else {
                uVar13 = 0;
                pppplStack_98 = (long ****)ppppplVar30;
code_r0x0c177f9b:
                pppplStack_58 = (long ****)CONCAT44(pppplStack_58._4_4_,uVar13);
                pppplStack_b8 = (long ****)(param_2 + 0xb5);
                cStack_1a8 = '\0';
                uStack_1a7 = 0;
                uStack_1a2 = 0;
                uStack_1a0 = 1;
                uStack_19a = 0;
                uStack_198 = 0;
                uStack_192 = 0;
                uStack_748 = 0x60000020;
                uStack_742 = 0;
                cStack_758 = (char)&cStack_1a8;
                uStack_757 = (undefined5)((ulong)&cStack_1a8 >> 8);
                uStack_752 = (undefined2)((ulong)&cStack_1a8 >> 0x30);
                uStack_750 = 0x1220fe88;
                uStack_74a = 0;
                pppplStack_40 = (long ****)param_2;
                cVar12 = (*(code *)&DAT_0fed4f60)(pppplStack_b8,&cStack_758);
                if (cVar12 != '\0') goto code_r0x0c178d5f;
                lVar22 = CONCAT26(uStack_1a2,CONCAT51(uStack_1a7,cStack_1a8));
                uVar11 = CONCAT26(uStack_19a,uStack_1a0);
                if (((long *****)pppplStack_108 != (long *****)CONCAT26(uStack_192,uStack_198)) ||
                   (iVar14 = (*(code *)&DAT_120cae9d)(pppplStack_110,uVar11), iVar14 != 0)) {
                  if (lVar22 != 0) {
                    (*(code *)&DAT_04732840)(uVar11,lVar22,1);
                  }
                  cStack_758 = (char)&pppplStack_118;
                  uStack_757 = (undefined5)((ulong)&pppplStack_118 >> 8);
                  uStack_752 = (undefined2)((ulong)&pppplStack_118 >> 0x30);
                  uStack_748 = SUB86(pppplStack_b8,0);
                  uStack_742 = (undefined2)((ulong)pppplStack_b8 >> 0x30);
                  uStack_740 = 0xfed4f60;
                  uStack_73a = 0;
                  puVar24 = &UNK_00396ef9;
                  goto code_r0x0c178099;
                }
                if (lVar22 != 0) {
                  (*(code *)&DAT_04732840)(uVar11,lVar22,1);
                }
                param_2 = (long *****)pppplStack_40;
                uVar13 = (uint)pppplStack_58;
              }
              uVar25 = (ulong)uVar13;
              ppplStack_288 = (long ***)param_2[0xb5];
              ppplStack_280 = (long ***)param_2[0xb6];
              plVar19 = (long *)(uVar25 & 0xff);
              func_0x0c1724e0(&cStack_1a8,&pppplStack_118,param_2[0xab],param_2[0xac]);
              if (CONCAT26(uStack_1a2,CONCAT51(uStack_1a7,cStack_1a8)) == -1) {
                lStack_120 = CONCAT26(uStack_19a,uStack_1a0);
                pppplStack_b8 = (long ****)CONCAT26(uStack_192,uStack_198);
                pppplVar21 = (long ****)CONCAT26(uStack_18a,uStack_190);
                uStack_728 = param_2[0xb7];
                uStack_720 = param_2[0xb8];
                cStack_758 = uStack_728 != (long ****)0x0;
                uStack_738 = (long ****)(ulong)(byte)cStack_758;
                pppplVar23 = param_2[0xb9];
                uStack_757 = 0;
                uStack_752 = 0;
                uStack_750 = 0;
                uStack_74a = 0;
                uStack_748 = SUB86(uStack_728,0);
                uStack_742 = (undefined2)((ulong)uStack_728 >> 0x30);
                uStack_740 = SUB86(uStack_720,0);
                uStack_73a = (undefined2)((ulong)uStack_720 >> 0x30);
                uStack_730 = 0;
                if ((bool)cStack_758 && pppplVar23 != (long ****)0x0) {
                  if (pppplVar21 != (long ****)0x0) {
                    pppplStack_50 = (long ****)((long)pppplVar21 * 8);
                    pppplStack_58 = (long ****)CONCAT44(pppplStack_58._4_4_,uVar13);
                    ppplStack_718 = (long ***)pppplVar23;
                    ppplStack_68 = (long ***)pppplVar21;
                    puStack_48 = param_1;
                    pppplStack_40 = (long ****)param_2;
                    do {
                      param_1 = puStack_48;
                      ppplStack_718 = (long ***)((long)ppplStack_718 + -1);
                      plVar17 = (long *)func_0x0deb4f50(&cStack_758);
                      if (plVar17 == (long *)0x0) goto code_r0x0c178e53;
                      plVar20 = (long *)*plVar17;
                      uVar25 = plVar17[1];
                      uVar27 = plVar17[2];
                      plVar26 = plVar20;
                      if (*(ushort *)((long)plVar20 + 0x112) <= uVar27) {
                        do {
                          plVar20 = (long *)*plVar26;
                          if (plVar20 == (long *)0x0) goto code_r0x0c178e8d;
                          uVar25 = uVar25 + 1;
                          puVar1 = (ushort *)(plVar26 + 0x22);
                          uVar27 = (ulong)*puVar1;
                          plVar26 = plVar20;
                        } while (*(ushort *)((long)plVar20 + 0x112) <= *puVar1);
                      }
                      if (uVar25 == 0) {
                        lVar22 = uVar27 + 1;
                        plVar19 = plVar20;
                      }
                      else {
                        plVar26 = plVar20 + uVar27 + 0x24;
                        uVar28 = uVar25;
                        if ((uVar25 & 7) != 0) {
                          uVar28 = 0;
                          do {
                            plVar19 = (long *)*plVar26;
                            plVar26 = plVar19 + 0x23;
                            uVar28 = uVar28 + 1;
                          } while ((uVar25 & 7) != uVar28);
                          uVar28 = uVar25 - uVar28;
                        }
                        if (7 < uVar25) {
                          do {
                            plVar19 = *(long **)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*
                                                  (long *)(*plVar26 + 0x118) + 0x118) + 0x118) +
                                                  0x118) + 0x118) + 0x118) + 0x118);
                            plVar26 = plVar19 + 0x23;
                            uVar28 = uVar28 - 8;
                          } while (uVar28 != 0);
                        }
                        lVar22 = 0;
                      }
                      *plVar17 = (long)plVar19;
                      plVar17[1] = 0;
                      plVar17[2] = lVar22;
                      lVar22 = plVar20[uVar27 * 3 + 2];
                      lVar2 = plVar20[uVar27 * 3 + 3];
                      ppppplVar30 = (long *****)0x0;
                      ppppplVar18 = (long *****)pppplStack_50;
                      while (((((lVar4 = *(long *)((long)pppplStack_b8 + (long)ppppplVar30),
                                lVar4 == 0 || (*(long *)(lVar4 + 0x10) != lVar2)) ||
                               (iVar14 = (*(code *)&DAT_120cae9d)
                                                   (*(undefined8 *)(lVar4 + 8),lVar22,lVar2),
                               ppppplVar18 = (long *****)pppplStack_50, iVar14 != 0)) ||
                              ((*(long *)(lVar4 + 0x20) != 0xd3 ||
                               (lVar5 = *(long *)(lVar4 + 0x30),
                               iVar14 = (*(code *)&DAT_120cae9d)
                                                  (*(long *)(lVar4 + 0x18) + 0x10,&UNK_011930ff,0xd3
                                                  ), ppppplVar18 = (long *****)pppplStack_50,
                               param_1 = puStack_48, lVar5 != 0)))) || (iVar14 != 0))) {
                        ppppplVar30 = ppppplVar30 + 1;
                        if (ppppplVar18 == ppppplVar30) goto code_r0x0c178cdf;
                      }
                      uVar25 = (ulong)pppplStack_58 & 0xffffffff;
                      param_2 = (long *****)pppplStack_40;
                      pppplVar21 = (long ****)ppplStack_68;
                    } while ((long ****)ppplStack_718 != (long ****)0x0);
                    goto code_r0x0c1785a2;
                  }
                  ppplStack_718 = (long ***)((long)pppplVar23 + -1);
                  plVar19 = (long *)func_0x0deb4f50(&cStack_758);
                  if (plVar19 != (long *)0x0) {
                    plVar17 = (long *)*plVar19;
                    uVar25 = plVar19[1];
                    uVar27 = plVar19[2];
                    plVar20 = plVar17;
                    if (*(ushort *)((long)plVar17 + 0x112) <= uVar27) {
                      do {
                        plVar17 = (long *)*plVar20;
                        if (plVar17 == (long *)0x0) goto code_r0x0c178e8d;
                        uVar25 = uVar25 + 1;
                        puVar1 = (ushort *)(plVar20 + 0x22);
                        uVar27 = (ulong)*puVar1;
                        plVar20 = plVar17;
                      } while (*(ushort *)((long)plVar17 + 0x112) <= *puVar1);
                    }
                    if (uVar25 == 0) {
                      lVar22 = uVar27 + 1;
                    }
                    else {
                      plVar20 = plVar17 + uVar27 + 0x24;
                      uVar27 = uVar25;
                      if ((uVar25 & 7) != 0) {
                        uVar27 = 0;
                        do {
                          plVar17 = (long *)*plVar20;
                          plVar20 = plVar17 + 0x23;
                          uVar27 = uVar27 + 1;
                        } while ((uVar25 & 7) != uVar27);
                        uVar27 = uVar25 - uVar27;
                      }
                      lVar22 = 0;
                      if (7 < uVar25) {
                        do {
                          plVar17 = *(long **)(*(long *)(*(long *)(*(long *)(*(long *)(*(long *)(*(
                                                  long *)(*plVar20 + 0x118) + 0x118) + 0x118) +
                                                  0x118) + 0x118) + 0x118) + 0x118);
                          plVar20 = plVar17 + 0x23;
                          uVar27 = uVar27 - 8;
                        } while (uVar27 != 0);
                      }
                    }
                    *plVar19 = (long)plVar17;
                    plVar19[1] = 0;
                    plVar19[2] = lVar22;
code_r0x0c178cdf:
                    func_0x0c02f960(&pppplStack_88,&UNK_01198551,0x4b);
                    uStack_192 = (undefined2)uStack_78;
                    uStack_190 = (undefined6)(uStack_78 >> 0x10);
                    uStack_1a2 = SUB82(pppplStack_88,0);
                    uStack_1a0 = (undefined6)((ulong)pppplStack_88 >> 0x10);
                    uStack_19a = SUB82(pppplStack_80,0);
                    uStack_198 = (undefined6)((ulong)pppplStack_80 >> 0x10);
                    *(undefined2 *)param_1 = 0x124;
                    *(ulong *)((long)param_1 + 2) =
                         CONCAT26(uStack_1a2,CONCAT51(uStack_1a7,cStack_1a8));
                    *(ulong *)((long)param_1 + 10) = CONCAT26(uStack_19a,uStack_1a0);
                    param_1[2] = pppplStack_80;
                    param_1[3] = uStack_78;
                    if (lStack_120 != 0) {
                      (*(code *)&DAT_04732840)(pppplStack_b8,lStack_120 << 3,8);
                    }
                    goto code_r0x0c1780f3;
                  }
code_r0x0c178e53:
                  (*(code *)&DAT_120a4420)(&UNK_1220e5e0);
                }
                else {
code_r0x0c1785a2:
                  pppplStack_40 = (long ****)param_2;
                  func_0x0c134810(&cStack_758,pppplVar21,0,8,0x4f0);
                  if (cStack_758 == '\0') {
                    pppplStack_200 = pppplStack_40 + 0xb0;
                    ppplStack_1d0 = (long ***)CONCAT26(uStack_742,uStack_748);
                    pppplStack_c8 = (long ****)0x0;
                    pppplStack_128 = pppplStack_b8 + (long)pppplVar21;
                    uStack_9c = 0;
                    pppplStack_58 = (long ****)CONCAT44(pppplStack_58._4_4_,(int)uVar25);
                    ppplStack_1d8 = pppplStack_40[0xaf];
                    ppppplVar18 = (long *****)pppplStack_b8;
                    pppplVar23 = (long ****)0x0;
                    pppplStack_d8 = (long ****)CONCAT26(uStack_74a,uStack_750);
                    ppplStack_d0 = ppplStack_1d0;
                    if ((long ****)ppplStack_1d8 == (long ****)0x0) goto code_r0x0c1787da;
                    while( true ) {
                      ppplStack_1c8 = pppplStack_40[0xab];
                      ppplStack_1b0 = pppplStack_40[0xac];
                      pppplVar21 = (long ****)pppplStack_40[0xae];
                      ppplStack_68 = (long ***)((long)ppplStack_1d8 * 0x4f0);
                      pppplStack_1b8 = pppplStack_c8;
                      ppplStack_60 = (long ***)pppplVar21;
                      if ((char)uVar25 == '\0') break;
                      if (ppppplVar18 == (long *****)pppplStack_128) goto code_r0x0c178beb;
                      ppplStack_68 = (long ***)((long)ppplStack_68 + (long)pppplVar21);
                      ppplStack_60 = (long ***)(pppplVar21 + 7);
                      pppplStack_1c0 = (long ****)ppppplVar18;
                      ppplStack_e0 = (long ***)pppplVar23;
                      ppplStack_1f8 = (long ***)pppplVar23;
                      while( true ) {
                        pppplVar31 = (long ****)*pppplStack_1c0;
                        pppplStack_1c0 = pppplStack_1c0 + 1;
                        pppplVar21 = (long ****)((long)ppplStack_e0 + 1);
                        pppplVar23 = (long ****)ppplStack_e0;
                        if (pppplVar31 != (long ****)0x0) break;
                        if (ppplStack_1b0 <= ppplStack_e0) goto code_r0x0c178d83;
                        pppplStack_50 = (long ****)ppplStack_1c8[(long)ppplStack_e0 * 0xc + 4];
                        ppplVar6 = (long ***)ppplStack_1c8[(long)ppplStack_e0 * 0xc + 5];
                        pppplVar31 = (long ****)ppplStack_60;
                        pppplVar34 = (long ****)ppplStack_68;
                        ppplStack_208 = ppplStack_e0;
                        ppplStack_e0 = (long ***)pppplVar21;
                        while (((*(int *)(pppplVar31 + -7) != 0x1c || (pppplVar31[-4] != ppplVar6))
                               || ((iVar14 = (*(code *)&DAT_120cae9d)
                                                       (pppplVar31[-5],pppplStack_50,ppplVar6),
                                   iVar14 != 0 ||
                                   (((pppplVar31[-2] == (long ***)0xd3 &&
                                     (ppplVar7 = *pppplVar31,
                                     iVar14 = (*(code *)&DAT_120cae9d)
                                                        (pppplVar31[-3] + 2,&UNK_011930ff,0xd3),
                                     ppplVar7 == (long ***)0x0)) &&
                                    (pppplVar34 = (long ****)ppplStack_68, iVar14 == 0))))))) {
                          pppplVar21 = pppplVar31 + 0x97;
                          pppplVar23 = (long ****)ppplStack_208;
                          pppplVar31 = pppplVar31 + 0x9e;
                          if (pppplVar21 == pppplVar34) goto code_r0x0c178a90;
                        }
                        if (pppplStack_1c0 == pppplStack_128) goto code_r0x0c178beb;
                      }
                      while( true ) {
                        pppplStack_50 = (long ****)pppplVar31[3];
                        ppplStack_68 = pppplVar31[4];
                        ppplStack_e0 = (long ***)pppplVar21;
                        if ((long ****)ppplStack_68 == (long ****)0x23) {
                          iVar14 = (*(code *)&DAT_120cae9d)(pppplStack_50 + 2,&UNK_0119859c,0x23);
                          uStack_9c = uStack_9c & 0xff;
                          if (iVar14 == 0) {
                            uStack_9c = 1;
                          }
                        }
                        pppplVar21 = (long ****)*pppplStack_90;
                        cStack_758 = (char)pppplVar21;
                        uStack_757 = (undefined5)((ulong)pppplVar21 >> 8);
                        uStack_752 = (undefined2)((ulong)pppplVar21 >> 0x30);
                        uStack_750 = SUB86(pppplStack_90[1],0);
                        uStack_74a = (undefined2)((ulong)pppplStack_90[1] >> 0x30);
                        (*(code *)&DAT_0b5917d0)(&uStack_1e9,&cStack_758,&ppplStack_288,pppplVar23);
                        if ((long ****)pppplVar31[6] == (long ****)0x0) {
                          (*(code *)&DAT_120846f0)(&cStack_758,pppplVar31);
                          LOCK();
                          pppplVar23 = (long ****)*pppplStack_50;
                          *pppplStack_50 = (long ***)((long)*pppplStack_50 + 1);
                          UNLOCK();
                          if ((long ****)*pppplStack_50 == (long ****)0x0 ||
                              SCARRY8((long)pppplVar23,1) != (long)*pppplStack_50 < 0)
                          goto code_r0x0c178e9a;
                          auVar35 = (*(code *)&DAT_0f762430)();
                          cStack_1a8 = cStack_758;
                          uStack_1a7 = uStack_757;
                          uStack_1a2 = uStack_752;
                          uStack_1a0 = uStack_750;
                          uStack_19a = uStack_74a;
                          uStack_198 = uStack_748;
                          uStack_192 = uStack_742;
                        }
                        else {
                          ppplVar6 = pppplVar31[5];
                          ppplStack_60 = pppplVar31[6];
                          (*(code *)&DAT_120846f0)(&cStack_758,pppplVar31);
                          auVar35._8_8_ = ppplStack_60;
                          auVar35._0_8_ = ppplVar6;
                          LOCK();
                          pppplVar23 = (long ****)*pppplStack_50;
                          *pppplStack_50 = (long ***)((long)*pppplStack_50 + 1);
                          UNLOCK();
                          if ((long ****)*pppplStack_50 == (long ****)0x0 ||
                              SCARRY8((long)pppplVar23,1) != (long)*pppplStack_50 < 0)
                          goto code_r0x0c178e9a;
                          LOCK();
                          pplVar3 = *ppplVar6;
                          *ppplVar6 = (long **)((long)*ppplVar6 + 1);
                          UNLOCK();
                          if (*ppplVar6 == (long **)0x0 ||
                              SCARRY8((long)pplVar3,1) != (long)*ppplVar6 < 0)
                          goto code_r0x0c178e9a;
                          uStack_198 = uStack_748;
                          uStack_192 = uStack_742;
                          cStack_1a8 = cStack_758;
                          uStack_1a7 = uStack_757;
                          uStack_1a2 = uStack_752;
                          uStack_1a0 = uStack_750;
                          uStack_19a = uStack_74a;
                        }
                        pppplVar23 = pppplStack_1b8;
                        uVar25 = (ulong)(uint)pppplStack_58;
                        pplStack_298 = (long **)CONCAT71(uStack_1e8,uStack_1e9);
                        pplStack_290 = (long **)CONCAT71(uStack_1e0,uStack_1e1);
                        pppplStack_88 = pppplStack_228;
                        pppplStack_80 = pppplStack_220;
                        uStack_78 = CONCAT71(uStack_78._1_7_,uStack_218);
                        cStack_758 = cStack_1a8;
                        uStack_757 = uStack_1a7;
                        uStack_752 = uStack_1a2;
                        uStack_750 = uStack_1a0;
                        uStack_74a = uStack_19a;
                        uStack_748 = uStack_198;
                        uStack_742 = uStack_192;
                        pppplVar21 = auVar35._8_8_;
                        if (pppplStack_1b8 == pppplStack_d8) {
                          ppplStack_60 = (long ***)auVar35._8_8_;
                          (*(code *)&DAT_0c130f40)(&pppplStack_d8);
                          ppplStack_1d0 = ppplStack_d0;
                          pppplVar21 = (long ****)ppplStack_60;
                        }
                        ppplStack_1d0[(long)pppplVar23 * 0x9e] = (long **)0x1c;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 1] =
                             (long **)CONCAT26(uStack_752,CONCAT51(uStack_757,cStack_758));
                        (ppplStack_1d0 + (long)pppplVar23 * 0x9e + 1)[1] =
                             (long **)CONCAT26(uStack_74a,uStack_750);
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 3] =
                             (long **)CONCAT26(uStack_742,uStack_748);
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 4] = (long **)pppplStack_50;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 5] = (long **)ppplStack_68;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 6] = (long **)auVar35._0_8_;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 7] = (long **)pppplVar21;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 0x97] = pplStack_298;
                        (ppplStack_1d0 + (long)pppplVar23 * 0x9e + 0x97)[1] = pplStack_290;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 0x99] = (long **)0x0;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 0x9a] = (long **)pppplStack_98;
                        ppplStack_1d0[(long)pppplVar23 * 0x9e + 0x9b] = (long **)pppplStack_88;
                        (ppplStack_1d0 + (long)pppplVar23 * 0x9e + 0x9b)[1] = (long **)pppplStack_80
                        ;
                        *(undefined1 *)(ppplStack_1d0 + (long)pppplVar23 * 0x9e + 0x9d) =
                             (undefined1)uStack_78;
                        pppplStack_c8 = (long ****)((long)pppplVar23 + 1);
                        ppplStack_1d8 = pppplStack_40[0xaf];
                        ppppplVar18 = (long *****)pppplStack_1c0;
                        pppplVar23 = (long ****)ppplStack_e0;
                        if ((long ****)ppplStack_1d8 != (long ****)0x0) break;
code_r0x0c1787da:
                        pppplStack_1b8 = pppplStack_c8;
                        if (ppppplVar18 == (long *****)pppplStack_128) goto code_r0x0c178beb;
                        pppplVar31 = *ppppplVar18;
                        if (pppplVar31 == (long ****)0x0) goto code_r0x0c178a90;
code_r0x0c1787f3:
                        pppplStack_1c0 = (long ****)(ppppplVar18 + 1);
                        pppplVar21 = (long ****)((long)pppplVar23 + 1);
                        pppplStack_1b8 = pppplStack_c8;
                      }
                    }
                    if (ppppplVar18 != (long *****)pppplStack_128) {
                      pppplVar31 = *ppppplVar18;
                      if (pppplVar31 != (long ****)0x0) goto code_r0x0c1787f3;
                      puStack_48 = param_1;
                      if (pppplVar23 < ppplStack_1b0) {
                        ppplVar6 = (long ***)ppplStack_1c8[(long)pppplVar23 * 0xc + 4];
                        ppplVar7 = (long ***)ppplStack_1c8[(long)pppplVar23 * 0xc + 5];
                        ppplStack_68 = ppplStack_68 + -0x9e;
                        for (pppplVar31 = (long ****)0x0;
                            (((param_1 = puStack_48,
                              *(int *)((long)pppplVar21 + (long)pppplVar31) != 0x1c ||
                              (*(long ****)((long)(pppplVar21 + 3) + (long)pppplVar31) != ppplVar7))
                             || ((iVar14 = (*(code *)&DAT_120cae9d)
                                                     (*(undefined8 *)
                                                       ((long)(pppplVar21 + 2) + (long)pppplVar31),
                                                      ppplVar6,ppplVar7), param_1 = puStack_48,
                                 iVar14 != 0 ||
                                 (((*(long *)((long)(pppplVar21 + 5) + (long)pppplVar31) == 0xd3 &&
                                   (lVar22 = *(long *)((long)(ppplStack_60 + 7) + (long)pppplVar31),
                                   iVar14 = (*(code *)&DAT_120cae9d)
                                                      (*(long *)((long)(ppplStack_60 + 4) +
                                                                (long)pppplVar31) + 0x10,
                                                       &UNK_011930ff,0xd3), param_1 = puStack_48,
                                   lVar22 == 0)) &&
                                  (pppplVar21 = (long ****)ppplStack_60, iVar14 == 0)))))) &&
                            (puStack_48 = param_1, (long ****)ppplStack_68 != pppplVar31));
                            pppplVar31 = pppplVar31 + 0x9e) {
                    /* WARNING: Read-only address (ram,0x011983e6) is written */
                        }
                      }
                      goto code_r0x0c178a90;
                    }
code_r0x0c178beb:
                    if (lStack_120 != 0) {
                      (*(code *)&DAT_04732840)(pppplStack_b8,lStack_120 << 3,8);
                      ppplStack_1d8 = pppplStack_40[0xaf];
                    }
                    pppplVar23 = pppplStack_200;
                    func_0x0bf96c80(pppplStack_200);
                    pppplVar23[2] = (long ***)pppplStack_c8;
                    *pppplVar23 = (long ***)pppplStack_d8;
                    pppplVar23[1] = ppplStack_d0;
                    pppplStack_40[0xb3] = ppplStack_1d8;
                    *(char *)(pppplStack_40 + 0xb4) = (char)pppplStack_58;
                    *(char *)((long)pppplStack_40 + 0x5a1) = (char)uStack_9c;
                    *(undefined1 *)param_1 = 0xff;
                    func_0x0bfa7a30(&pppplStack_118);
                    puVar29 = puStack_130;
                    goto code_r0x0c1781bc;
                  }
                }
                (*(code *)&DAT_1208422d)();
                goto code_r0x0c178e6d;
              }
              ppplStack_718 = ppplStack_168;
              uStack_710 = uStack_160;
              uStack_728 = (long ****)CONCAT44(uStack_174,uStack_178);
              uStack_720 = (long ****)CONCAT44(uStack_16c,uStack_170);
              uStack_738 = (long ****)CONCAT44(uStack_184,uStack_188);
              uStack_730 = CONCAT44(uStack_17c,uStack_180);
              uStack_748 = uStack_198;
              uStack_742 = uStack_192;
              uStack_740 = uStack_190;
              uStack_73a = uStack_18a;
              cStack_758 = cStack_1a8;
              uStack_757 = uStack_1a7;
              uStack_752 = uStack_1a2;
              uStack_750 = uStack_1a0;
              uStack_74a = uStack_19a;
              pppplStack_d8 = (long ****)0x0;
              ppplStack_d0 = (long ***)0x1;
              pppplStack_c8 = (long ****)0x0;
              uStack_78 = 0x60000020;
              pppplStack_88 = (long ****)&pppplStack_d8;
              pppplStack_80 = (long ****)&UNK_1220fe88;
              cVar12 = (*(code *)&DAT_0c7cdef0)(&cStack_758,&pppplStack_88);
              pppplVar23 = pppplStack_c8;
              if (cVar12 != '\0') goto code_r0x0c178d5f;
              pppplStack_b8 = pppplStack_d8;
              ppplStack_b0 = ppplStack_d0;
              func_0x0bfa7b20(&cStack_1a8);
              param_1[1] = pppplStack_b8;
              param_1[2] = ppplStack_b0;
              param_1[3] = pppplVar23;
              *(undefined2 *)param_1 = 0x124;
            }
            else {
              cStack_758 = (char)&pppplStack_118;
              uStack_757 = (undefined5)((ulong)&pppplStack_118 >> 8);
              uStack_752 = (undefined2)((ulong)&pppplStack_118 >> 0x30);
              puVar24 = &UNK_002f42d7;
code_r0x0c178099:
              uStack_74a = 0;
              uStack_750 = 0xc2267f0;
              (*(code *)&DAT_12089060)(&cStack_1a8,puVar24,&cStack_758);
              uStack_752 = (undefined2)CONCAT51(uStack_1a7,cStack_1a8);
              uStack_750 = (undefined6)
                           (CONCAT26(uStack_1a2,CONCAT51(uStack_1a7,cStack_1a8)) >> 0x10);
              uStack_74a = (undefined2)uStack_1a0;
              uStack_748 = (undefined6)(CONCAT26(uStack_19a,uStack_1a0) >> 0x10);
              uStack_742 = (undefined2)uStack_198;
              uStack_740 = (undefined6)(CONCAT26(uStack_192,uStack_198) >> 0x10);
              *(undefined2 *)param_1 = 0x124;
              *(ulong *)((long)param_1 + 2) = CONCAT26(uStack_752,CONCAT51(uStack_757,cStack_758));
              *(ulong *)((long)param_1 + 10) = CONCAT26(uStack_74a,uStack_750);
              param_1[2] = CONCAT62(uStack_748,uStack_74a);
              param_1[3] = CONCAT62(uStack_740,uStack_742);
            }
          }
          else {
            (*(code *)&DAT_04732870)();
            puVar15 = (undefined8 *)(*(code *)&DAT_04732830)(0x48,1);
            if (puVar15 == (undefined8 *)0x0) goto code_r0x0c178e7d;
            puVar15[6] = 0x7374692072657466;
            puVar15[7] = 0x616e696d72657420;
            puVar15[4] = 0x746c757365722d6c;
            puVar15[5] = 0x6120686374616220;
            puVar15[2] = 0x6961746e6f63206e;
            puVar15[3] = 0x6f6f74206120736e;
            *puVar15 = 0x20656c6261727564;
            puVar15[1] = 0x757220646c696863;
            puVar15[8] = 0x64726f636572206c;
            *(undefined2 *)param_1 = 0x124;
            param_1[1] = 0x48;
            param_1[2] = puVar15;
            param_1[3] = 0x48;
          }
        }
        else {
          uStack_78 = puVar29[3];
          pppplStack_88 = (long ****)puVar29[1];
          pppplStack_80 = (long ****)puVar29[2];
          pppplStack_58 = (long ****)ppppplVar18;
          pppplStack_40 = (long ****)param_2;
          (*(code *)&DAT_0c969a00)(&cStack_758,&pppplStack_88);
          pppplVar23 = pppplStack_80;
          if (cStack_758 == -1) {
            pppplStack_100 = pppplStack_80 + uStack_78 * 0x2a;
            pppplStack_118 = pppplStack_80;
            pppplStack_110 = pppplStack_80;
            pppplStack_50 = pppplStack_88;
            pppplStack_108 = pppplStack_88;
            pppplStack_90 = pppplStack_80;
            ppppplVar30 = (long *****)pppplStack_80;
            ppppplVar18 = (long *****)pppplStack_80;
            pppplStack_98 = pppplStack_100;
            puVar15 = param_1;
            if (uStack_78 != 0) {
              do {
                puStack_48 = puVar15;
                ppppplVar33 = ppppplVar18 + 0x2a;
                pppplVar23 = *ppppplVar18;
                param_1 = puStack_48;
                ppppplVar30 = ppppplVar33;
                if (pppplVar23 == (long ****)0xffffffffffffffff) break;
                pppplVar21 = ppppplVar18[0x23];
                pppplVar31 = ppppplVar18[0x26];
                uStack_1e8 = SUB87(ppppplVar18[0x24],0);
                uStack_1e1 = (undefined1)((ulong)ppppplVar18[0x24] >> 0x38);
                uStack_1e0 = SUB87(ppppplVar18[0x25],0);
                uStack_1d9 = (undefined1)((ulong)ppppplVar18[0x25] >> 0x38);
                pppplStack_c8 =
                     (long ****)CONCAT71(pppplStack_c8._1_7_,*(undefined1 *)(ppppplVar18 + 0x29));
                pppplStack_d8 = ppppplVar18[0x27];
                ppplStack_d0 = (long ***)ppppplVar18[0x28];
                (*(code *)&DAT_120cba68)(&uStack_748,ppppplVar18 + 1,0x110);
                uStack_750 = SUB86(pppplVar23,0);
                uStack_74a = (undefined2)((ulong)pppplVar23 >> 0x30);
                cStack_758 = 'H';
                uStack_757 = 0;
                uStack_752 = 0;
                uStack_1e9 = 1;
                func_0x0c179120(&cStack_1a8,pppplStack_40,&cStack_758,&uStack_1e9,pppplVar21,
                                pppplStack_b8,pppplStack_58,pppplVar31,&pppplStack_d8);
                param_1 = puStack_48;
                if (cStack_1a8 != -1) {
                  puStack_48[0xe] = uStack_138;
                  puStack_48[0xc] = uStack_148;
                  puStack_48[0xd] = uStack_140;
                  puStack_48[10] = uStack_158;
                  puStack_48[0xb] = uStack_150;
                  puStack_48[8] = ppplStack_168;
                  puStack_48[9] = uStack_160;
                  *(undefined4 *)(puStack_48 + 6) = uStack_178;
                  *(undefined4 *)((long)puStack_48 + 0x34) = uStack_174;
                  *(undefined4 *)(puStack_48 + 7) = uStack_170;
                  *(undefined4 *)((long)puStack_48 + 0x3c) = uStack_16c;
                  *(undefined4 *)(puStack_48 + 4) = uStack_188;
                  *(undefined4 *)((long)puStack_48 + 0x24) = uStack_184;
                  *(undefined4 *)(puStack_48 + 5) = uStack_180;
                  *(undefined4 *)((long)puStack_48 + 0x2c) = uStack_17c;
                  puStack_48[2] = CONCAT26(uStack_192,uStack_198);
                  puStack_48[3] = CONCAT26(uStack_18a,uStack_190);
                  *puStack_48 = CONCAT26(uStack_1a2,CONCAT51(uStack_1a7,cStack_1a8));
                  puStack_48[1] = CONCAT26(uStack_19a,uStack_1a0);
                  pppplStack_110 = (long ****)ppppplVar33;
                  func_0x0e387370(&pppplStack_118);
                  uVar25 = *puStack_130;
                  uVar27 = 1;
                  puVar29 = puStack_130;
                  param_3 = plStack_c0;
                  if ((long)uVar25 < 0) {
                    uVar27 = uVar25 ^ 0x8000000000000000;
                  }
                  goto joined_r0x0c177ee3;
                }
                ppppplVar32 = ppppplVar18 + 0x2a;
                ppppplVar30 = (long *****)pppplStack_98;
                ppppplVar18 = ppppplVar33;
                puVar15 = puStack_48;
              } while (ppppplVar32 != (long *****)pppplStack_98);
            }
            uVar25 = (ulong)((long)pppplStack_98 - (long)ppppplVar30) / 0x150;
            pppplStack_110 = (long ****)ppppplVar30;
            if ((long *****)pppplStack_98 != ppppplVar30) {
              do {
                func_0x0e171af0(ppppplVar30);
                if (ppppplVar30[0x1f] != (long ****)0x0) {
                  (*(code *)&DAT_04732840)(ppppplVar30[0x20],ppppplVar30[0x1f],1);
                }
                ppppplVar30 = ppppplVar30 + 0x2a;
                uVar25 = uVar25 - 1;
              } while (uVar25 != 0);
            }
            puVar29 = puStack_130;
            if ((long *****)pppplStack_50 != (long *****)0x0) {
              (*(code *)&DAT_04732840)(pppplStack_90,(long)pppplStack_50 * 0x150,8);
            }
            *(undefined1 *)param_1 = 0xff;
            goto code_r0x0c1781bc;
          }
          pppplStack_b8 = (long ****)CONCAT26(uStack_752,CONCAT51(uStack_757,cStack_758));
          pppplStack_58 = (long ****)CONCAT26(uStack_74a,uStack_750);
          pppplStack_40 = (long ****)CONCAT26(uStack_742,uStack_748);
          ppppplVar18 = (long *****)pppplStack_80;
          for (uVar25 = uStack_78; uVar25 != 0; uVar25 = uVar25 - 1) {
            func_0x0b4714f0(ppppplVar18);
            if (ppppplVar18[0x1f] != (long ****)0x0) {
              (*(code *)&DAT_04732840)(ppppplVar18[0x20],ppppplVar18[0x1f],1);
            }
            ppppplVar18 = ppppplVar18 + 0x2a;
          }
          if ((long *****)pppplStack_88 != (long *****)0x0) {
            (*(code *)&DAT_04732840)(pppplVar23,(long)pppplStack_88 * 0x150,8);
          }
          pppplStack_118 = pppplStack_b8;
          pppplStack_110 = pppplStack_58;
          pppplStack_108 = pppplStack_40;
          cStack_1a8 = '\0';
          uStack_1a7 = 0;
          uStack_1a2 = 0;
          uStack_1a0 = 1;
          uStack_19a = 0;
          uStack_198 = 0;
          uStack_192 = 0;
          uStack_748 = 0x60000020;
          uStack_742 = 0;
          cStack_758 = (char)&cStack_1a8;
          uStack_757 = (undefined5)((ulong)&cStack_1a8 >> 8);
          uStack_752 = (undefined2)((ulong)&cStack_1a8 >> 0x30);
          uStack_750 = 0x1220fe88;
          uStack_74a = 0;
          cVar12 = (*(code *)&DAT_0ca52160)(&pppplStack_118,&cStack_758);
          if (cVar12 == '\0') {
            auVar10._1_5_ = uStack_1a7;
            auVar10[0] = cStack_1a8;
            auVar10._6_2_ = uStack_1a2;
            auVar10._8_6_ = uStack_1a0;
            auVar10._14_2_ = uStack_19a;
            *(undefined2 *)param_1 = 0x124;
            *(undefined1 (*) [16])(param_1 + 1) = auVar10;
            param_1[3] = CONCAT26(uStack_192,uStack_198);
            uVar25 = *puStack_130;
            uVar27 = 1;
            puVar29 = puStack_130;
            param_3 = plStack_c0;
            if ((long)uVar25 < 0) {
              uVar27 = uVar25 ^ 0x8000000000000000;
            }
joined_r0x0c177ee3:
            puStack_130 = puVar29;
            plStack_c0 = param_3;
            if (uVar27 != 0) {
              if (uVar27 != 1) goto code_r0x0c177f09;
              goto code_r0x0c177788;
            }
            goto code_r0x0c177ee9;
          }
code_r0x0c178d5f:
          (*(code *)&DAT_120a9080)(&UNK_0119a7fb,0x37,&uStack_31,&UNK_1220feb8,&UNK_1220fed8);
          pppplVar21 = (long ****)ppplStack_e0;
code_r0x0c178d83:
          ppplStack_e0 = (long ***)pppplVar21;
          pppplVar23 = (long ****)ppplStack_1f8;
          if (ppplStack_1f8 <= ppplStack_1b0) {
            pppplVar23 = (long ****)ppplStack_1b0;
          }
code_r0x0c178a90:
          (*(code *)&DAT_120846f0)(&uStack_750,&pppplStack_118);
          cStack_758 = '\x03';
          uStack_757 = 0;
          uStack_752 = 0x8000;
          uStack_738 = pppplVar23;
          func_0x0c1faf10(&pppplStack_88,&cStack_758);
          uStack_192 = (undefined2)uStack_78;
          uStack_190 = (undefined6)(uStack_78 >> 0x10);
          uStack_1a2 = SUB82(pppplStack_88,0);
          uStack_1a0 = (undefined6)((ulong)pppplStack_88 >> 0x10);
          uStack_19a = SUB82(pppplStack_80,0);
          uStack_198 = (undefined6)((ulong)pppplStack_80 >> 0x10);
          *(undefined2 *)param_1 = 0x124;
          *(ulong *)((long)param_1 + 2) = CONCAT26(uStack_1a2,CONCAT51(uStack_1a7,cStack_1a8));
          *(ulong *)((long)param_1 + 10) = CONCAT26(uStack_19a,uStack_1a0);
          param_1[2] = pppplStack_80;
          param_1[3] = uStack_78;
          func_0x0bfa7b20(&cStack_758);
          if (lStack_120 != 0) {
            (*(code *)&DAT_04732840)(pppplStack_b8,lStack_120 << 3,8);
          }
          func_0x0bf98e70(&pppplStack_d8);
        }
code_r0x0c1780f3:
        if ((long *****)pppplStack_118 != (long *****)0x0) {
          (*(code *)&DAT_04732840)(pppplStack_110,pppplStack_118,1);
        }
        lVar22 = CONCAT44(uStack_ec,uStack_f0);
        if (lVar22 != 0) {
          puVar15 = (undefined8 *)(CONCAT44(uStack_f4,uStack_f8) + 0x18);
          do {
            if (puVar15[-3] != 0) {
              (*(code *)&DAT_04732840)(puVar15[-2],puVar15[-3],1);
            }
            plVar19 = (long *)*puVar15;
            LOCK();
            *plVar19 = *plVar19 + -1;
            UNLOCK();
            if (*plVar19 == 0) {
              (*(code *)&DAT_0f2d88a0)(puVar15);
              plVar19 = (long *)puVar15[2];
              LOCK();
              *plVar19 = *plVar19 + -1;
              lVar2 = *plVar19;
              UNLOCK();
            }
            else {
              plVar19 = (long *)puVar15[2];
              LOCK();
              *plVar19 = *plVar19 + -1;
              lVar2 = *plVar19;
              UNLOCK();
            }
            if (lVar2 == 0) {
              (*(code *)&DAT_0f2d88a0)(puVar15 + 2);
            }
            puVar15 = puVar15 + 8;
            lVar22 = lVar22 + -1;
          } while (lVar22 != 0);
        }
        puVar29 = puStack_130;
        if ((long *****)pppplStack_100 != (long *****)0x0) {
          (*(code *)&DAT_04732840)(CONCAT44(uStack_f4,uStack_f8),(long)pppplStack_100 << 6,8);
          puVar29 = puStack_130;
        }
      }
code_r0x0c1781bc:
      (*(code *)&DAT_04732840)(puVar29,0x30,8);
      param_3 = plStack_c0;
      if ((char)lStack_278 != '\x1e') {
        func_0x0bfa3480(&lStack_278);
        param_3 = plStack_c0;
      }
      goto code_r0x0c177f31;
    }
    if (*(char *)((long)param_2 + 0x64b) == '\0') {
      *(undefined1 *)((long)param_2 + 0x64a) = 1;
      *(undefined1 *)param_1 = 0xff;
    }
    else {
      (*(code *)&DAT_04732870)();
      pauVar16 = (undefined1 (*) [16])(*(code *)&DAT_04732830)(0x2b,1);
      if (pauVar16 == (undefined1 (*) [16])0x0) {
code_r0x0c178e6d:
        (*(code *)&DAT_1208422d)(1,0x2b);
code_r0x0c178e7d:
        (*(code *)&DAT_1208422d)(1,0x48);
code_r0x0c178e8d:
        (*(code *)&DAT_120a4420)(&UNK_1220dc00);
code_r0x0c178e9a:
                    /* WARNING: Does not return */
        pcVar8 = (code *)invalidInstructionException();
        (*pcVar8)();
      }
      *(undefined8 *)(pauVar16[1] + 0xb) = 0x676965726f662061;
      *(undefined8 *)(pauVar16[2] + 3) = 0x6469206e7572206e;
      *(undefined8 *)pauVar16[1] = 0x6961746e6f632067;
      *(undefined8 *)(pauVar16[1] + 8) = 0x726f66206120736e;
      *pauVar16 = _UNK_011983e6;
      *(undefined2 *)param_1 = 0x324;
      param_1[1] = 0x2b;
      param_1[2] = pauVar16;
      param_1[3] = 0x2b;
    }
    uVar25 = *puVar29;
    uVar27 = 1;
    if ((long)uVar25 < 0) {
      uVar27 = uVar25 ^ 0x8000000000000000;
    }
    if (uVar27 == 0) {
code_r0x0c177ee9:
      uVar25 = puVar29[1];
      func_0x0bf9d510(uVar25);
      lVar22 = 0x4b8;
code_r0x0c177f03:
      (*(code *)&DAT_04732840)(uVar25,lVar22,8);
    }
    else if (uVar27 == 1) {
code_r0x0c177788:
      plStack_c0 = param_3;
      puStack_48 = param_1;
      if (uVar25 != 0) {
        (*(code *)&DAT_04732840)(puVar29[1],uVar25,1);
      }
      uVar25 = puVar29[5];
      if (uVar25 != 0) {
        puVar15 = (undefined8 *)(puVar29[4] + 0x18);
        do {
          if (puVar15[-3] != 0) {
            (*(code *)&DAT_04732840)(puVar15[-2],puVar15[-3],1);
          }
          plVar19 = (long *)*puVar15;
          LOCK();
          *plVar19 = *plVar19 + -1;
          UNLOCK();
          if (*plVar19 == 0) {
            (*(code *)&DAT_0f2d88a0)(puVar15);
            plVar19 = (long *)puVar15[2];
            LOCK();
            *plVar19 = *plVar19 + -1;
            lVar22 = *plVar19;
            UNLOCK();
          }
          else {
            plVar19 = (long *)puVar15[2];
            LOCK();
            *plVar19 = *plVar19 + -1;
            lVar22 = *plVar19;
            UNLOCK();
          }
          if (lVar22 == 0) {
            (*(code *)&DAT_0f2d88a0)(puVar15 + 2);
          }
          puVar15 = puVar15 + 8;
          uVar25 = uVar25 - 1;
        } while (uVar25 != 0);
      }
      param_3 = plStack_c0;
      param_1 = puStack_48;
      if (puVar29[3] != 0) {
        uVar25 = puVar29[4];
        lVar22 = puVar29[3] << 6;
        goto code_r0x0c177f03;
      }
    }
    else {
      uVar25 = puVar29[3];
      puStack_48 = param_1;
      if (uVar25 != 0) {
        uVar27 = puVar29[2];
        do {
          func_0x0b4714f0(uVar27);
          if (*(long *)(uVar27 + 0xf8) != 0) {
            (*(code *)&DAT_04732840)(*(undefined8 *)(uVar27 + 0x100),*(long *)(uVar27 + 0xf8),1);
          }
          uVar27 = uVar27 + 0x150;
          uVar25 = uVar25 - 1;
        } while (uVar25 != 0);
      }
      param_1 = puStack_48;
      if (puVar29[1] != 0) {
        uVar25 = puVar29[2];
        lVar22 = puVar29[1] * 0x150;
        goto code_r0x0c177f03;
      }
    }
code_r0x0c177f09:
    (*(code *)&DAT_04732840)(puVar29,0x30,8);
    if ((char)lStack_278 == '\x1e') goto code_r0x0c177f31;
  }
  else {
    *(undefined1 *)param_1 = 0xff;
  }
  func_0x0bfa3480(&lStack_278);
code_r0x0c177f31:
  if (*param_3 != 0) {
    (*(code *)&DAT_04732840)(param_3[1],*param_3,1);
  }
  return param_1;
}

