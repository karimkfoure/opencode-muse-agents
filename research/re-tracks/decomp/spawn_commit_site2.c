
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
spawn_commit_site2(long *param_1,undefined1 (*param_2) [16],undefined1 (*param_3) [16],long *param_4
                  )

{
  char cVar1;
  short sVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined1 uVar11;
  undefined1 auStack_358 [8];
  undefined8 *puStack_350;
  undefined8 uStack_348;
  undefined8 uStack_340;
  undefined1 auStack_338 [8];
  undefined8 *puStack_330;
  undefined8 uStack_328;
  undefined8 uStack_320;
  char acStack_310 [8];
  undefined8 *puStack_308;
  undefined8 uStack_300;
  undefined8 uStack_2f8;
  char acStack_2f0 [8];
  undefined8 *puStack_2e8;
  undefined8 uStack_2e0;
  undefined8 uStack_2d8;
  undefined8 uStack_2b0;
  undefined1 auStack_2a0 [8];
  undefined8 *puStack_298;
  undefined8 uStack_288;
  undefined8 *puStack_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined8 *puStack_268;
  undefined8 uStack_260;
  byte abStack_250 [8];
  long lStack_248;
  undefined8 uStack_240;
  byte abStack_230 [8];
  long lStack_228;
  undefined8 uStack_220;
  undefined1 (*pauStack_210) [16];
  long lStack_208;
  long lStack_200;
  undefined8 *puStack_1f8;
  long *plStack_1a8;
  undefined8 uStack_1a0;
  undefined8 *puStack_198;
  undefined8 uStack_190;
  uint uStack_180;
  undefined8 uStack_178;
  undefined8 *puStack_170;
  undefined8 uStack_168;
  long lStack_158;
  undefined8 *puStack_150;
  undefined8 *puStack_148;
  undefined8 uStack_140;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined8 uStack_130;
  byte abStack_128 [8];
  long lStack_120;
  undefined8 uStack_118;
  long lStack_108;
  undefined8 *puStack_100;
  undefined8 *puStack_f8;
  undefined8 uStack_f0;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined8 uStack_e0;
  long lStack_d8;
  undefined8 *puStack_d0;
  undefined8 *puStack_c8;
  undefined8 uStack_c0;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  long lStack_a8;
  undefined8 *puStack_a0;
  undefined8 *puStack_98;
  undefined8 uStack_90;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  long lStack_70;
  undefined8 *puStack_68;
  undefined8 *puStack_60;
  undefined8 uStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  char cStack_3a;
  long lStack_38;
  
  lVar3 = *param_1;
  if (lVar3 == -2) {
    if ((param_3 == (undefined1 (*) [16])0x1e) &&
       (*param_2 == _UNK_00213e40 && *(undefined1 (*) [16])(*param_2 + 0xe) == _UNK_002212f0)) {
      lVar3 = *param_4;
      puVar6 = (undefined8 *)
               (*(code *)&DAT_0ff4bdb0)
                         (&UNK_006d3f2b,0x12,
                          ((ulong)(*(long *)(lVar3 + 0x218) != -1) -
                          (ulong)(*(short *)(lVar3 + 0x3c8) == 0)) + 4 +
                          (ulong)(*(long *)(lVar3 + 0x3b0) != -1));
      return puVar6;
    }
    puVar6 = (undefined8 *)(*(code *)&DAT_0ff4ab00)();
    return puVar6;
  }
  uVar11 = param_3 == (undefined1 (*) [16])0x0;
  if (-1 < (long)param_3) goto code_r0x06de2a88;
  param_1 = (long *)0x0;
  do {
    uVar11 = 1;
    param_2 = param_3;
    (*(code *)&DAT_1208422d)(param_1,param_3);
code_r0x06de2a88:
    lStack_38 = *param_4;
    if ((bool)uVar11) {
      lVar7 = 1;
      goto joined_r0x06de2b39;
    }
    plStack_1a8 = param_1;
    (*(code *)&DAT_04732870)();
    param_1 = (long *)0x1;
    lVar7 = (*(code *)&DAT_04732830)(param_3,1);
  } while (lVar7 == 0);
  (*(code *)&DAT_120cba68)(lVar7,param_2,param_3);
  param_1 = plStack_1a8;
joined_r0x06de2b39:
  plStack_1a8 = param_1;
  if ((lVar3 != -1) && (lVar3 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar3,1);
  }
  lVar5 = lStack_38;
  param_1[1] = lVar7;
  param_1[2] = (long)param_3;
  *param_1 = -1;
  lStack_208 = param_1[1];
  lStack_200 = param_1[2];
  sVar2 = *(short *)(lStack_38 + 0x3c8);
  lVar3 = *(long *)(lStack_38 + 0x218);
  puVar6 = *(undefined8 **)(lStack_38 + 0x3b0);
  lStack_158 = -1;
  uStack_140 = 0;
  uStack_130 = 0;
  pauStack_210 = param_3;
  func_0x06e2f9a0(&lStack_158,&UNK_006d34cd,0xe,lStack_38 + 0x3fc);
  lVar7 = lStack_158;
  if (lStack_158 == -2) {
code_r0x06de2beb:
    puVar8 = (undefined8 *)(*(code *)&DAT_0ff4ab00)();
  }
  else {
    puStack_1f8 = puVar6;
    (*(code *)&DAT_04732870)();
    puVar8 = (undefined8 *)(*(code *)&DAT_04732830)(0xe,1);
    if (puVar8 == (undefined8 *)0x0) {
code_r0x06de41e6:
      (*(code *)&DAT_1208422d)(1,0xe);
code_r0x06de41f6:
      puVar8 = (undefined8 *)func_0x06e28560(&lStack_70,&UNK_006ba124,0xd,lStack_38 + 0x3fe);
      if (puVar8 == (undefined8 *)0x0) {
        uStack_b8 = uStack_50;
        uStack_b4 = uStack_4c;
        uStack_b0 = (undefined4)uStack_48;
        uStack_ac = uStack_48._4_4_;
        puStack_c8 = puStack_60;
        uStack_c0 = uStack_58;
        lStack_d8 = lStack_70;
        puStack_d0 = puStack_68;
        (*(code *)&DAT_0ff4b870)(&lStack_108,&lStack_d8);
        puVar10 = puStack_170;
        puVar8 = puStack_100;
        if ((char)lStack_108 != -1) {
          puStack_98 = puStack_f8;
          uStack_90 = uStack_f0;
          lStack_a8 = lStack_108;
          puStack_a0 = puStack_100;
          func_0x077d6570(abStack_128,puVar6,&uStack_178,&lStack_a8);
          if (abStack_128[0] < 3) {
            if (2 < abStack_128[0]) {
code_r0x06de42d7:
              func_0x07813660(&lStack_120);
            }
          }
          else if (abStack_128[0] == 3) {
            if (lStack_120 != 0) {
              uVar9 = 1;
code_r0x06de4327:
              (*(code *)&DAT_04732840)(uStack_118,lStack_120,uVar9);
            }
          }
          else if (abStack_128[0] == 4) {
            func_0x07c89080(&lStack_120);
            if (lStack_120 != 0) {
              lStack_120 = lStack_120 << 5;
              uVar9 = 8;
              goto code_r0x06de4327;
            }
          }
          else if (abStack_128[0] != 0xff) goto code_r0x06de42d7;
          if ((((sVar2 != 0) &&
               (puVar8 = (undefined8 *)func_0x06dc9c60(&lStack_158,lStack_38 + 0x3c8),
               puVar8 != (undefined8 *)0x0)) ||
              ((lVar3 != -1 &&
               (puVar8 = (undefined8 *)func_0x06dccc70(&lStack_158,lStack_38 + 0x218),
               puVar8 != (undefined8 *)0x0)))) ||
             ((puStack_1f8 != (undefined8 *)0xffffffffffffffff &&
              (puVar8 = (undefined8 *)
                        func_0x06dbb490(&lStack_158,&UNK_006d3f70,0xb,lStack_38 + 0x3b0),
              puVar8 != (undefined8 *)0x0)))) goto code_r0x06de2e56;
          uStack_b8 = uStack_138;
          uStack_b4 = uStack_134;
          uStack_b0 = (undefined4)uStack_130;
          uStack_ac = uStack_130._4_4_;
          puStack_c8 = puStack_148;
          uStack_c0 = uStack_140;
          lStack_d8 = lStack_158;
          puStack_d0 = puStack_150;
          (*(code *)&DAT_0ff4b870)(&lStack_70,&lStack_d8);
          if ((byte)lStack_70 == -1) goto joined_r0x06de444f;
          puStack_c8 = puStack_60;
          uStack_c0 = uStack_58;
          lStack_d8 = lStack_70;
          puStack_d0 = puStack_68;
          func_0x077d6570(&lStack_a8,plStack_1a8 + 3,&pauStack_210,&lStack_d8);
          if ((byte)lStack_a8 < 3) {
            if ((byte)lStack_a8 < 3) {
              return (undefined8 *)0x0;
            }
code_r0x06de446f:
            func_0x07813660(&puStack_a0);
          }
          else {
            if ((byte)lStack_a8 == 3) {
              if (puStack_a0 == (undefined8 *)0x0) {
                return (undefined8 *)0x0;
              }
              uVar9 = 1;
              puVar6 = puStack_a0;
            }
            else {
              if ((byte)lStack_a8 != 4) {
                if ((byte)lStack_a8 == 0xff) {
                  return (undefined8 *)0x0;
                }
                goto code_r0x06de446f;
              }
              func_0x07c89080(&puStack_a0);
              if (puStack_a0 == (undefined8 *)0x0) {
                return (undefined8 *)0x0;
              }
              uVar9 = 8;
              puVar6 = (undefined8 *)((long)puStack_a0 << 5);
            }
            (*(code *)&DAT_04732840)(puStack_98,puVar6,uVar9);
          }
                    /* WARNING: Read-only address (ram,0x00213e40) is written */
                    /* WARNING: Read-only address (ram,0x002212f0) is written */
          return (undefined8 *)0x0;
        }
      }
      else {
code_r0x06de421b:
        func_0x06895de0(&lStack_70);
        puVar10 = puStack_170;
      }
    }
    else {
      *(undefined8 *)((long)puVar8 + 6) = 0x6e6f697369636564;
      *puVar8 = 0x65645f6e77617073;
      if ((lVar7 != -1) && (lStack_158 != 0)) {
        (*(code *)&DAT_04732840)(puStack_150,lStack_158,1);
      }
      puStack_148 = (undefined8 *)0xe;
      lStack_158 = -1;
      uStack_278 = 0xe;
      uStack_288 = 0xe;
      cVar1 = *(char *)(lVar5 + 0x20f);
      lStack_108 = -1;
      uStack_f0 = 0;
      uStack_e0 = 0;
      puStack_280 = puVar8;
      puStack_150 = puVar8;
      func_0x06e2f9a0(&lStack_108,&UNK_006d34cd,0xe,lVar5 + 0x208);
      lVar7 = lStack_108;
      if (lStack_108 == -2) {
code_r0x06de2cf5:
        puStack_308 = (undefined8 *)(*(code *)&DAT_0ff4ab00)();
        goto code_r0x06de2e33;
      }
      cStack_3a = cVar1;
      (*(code *)&DAT_04732870)();
      puVar6 = (undefined8 *)(*(code *)&DAT_04732830)(0xb,1);
      if (puVar6 == (undefined8 *)0x0) {
        (*(code *)&DAT_1208422d)(1,0xb);
code_r0x06de3b1e:
        (*(code *)&DAT_1208422d)(1,0xc);
        (*(code *)&DAT_1208422d)(1,0xd);
        (*(code *)&DAT_1208422d)(1,5);
        (*(code *)&DAT_1208422d)(1,0x18);
        (*(code *)&DAT_1208422d)(1,0x13);
        (*(code *)&DAT_04732840)(uStack_2b0,0x12,1);
        puVar6 = puStack_268;
        if ((puStack_268 != (undefined8 *)0x0) ||
           (puVar6 = (undefined8 *)
                     func_0x06e167d0(&lStack_a8,&UNK_006d382d,6,*(undefined8 *)(lStack_38 + 0x1f0),
                                     *(undefined8 *)(lStack_38 + 0x1f8)),
           puVar6 != (undefined8 *)0x0)) {
          func_0x06d08070(&lStack_a8);
          uVar9 = 0x13;
          goto code_r0x06de2e28;
        }
        uStack_b8 = uStack_88;
        uStack_b4 = uStack_84;
        uStack_b0 = uStack_80;
        uStack_ac = uStack_7c;
        puStack_c8 = puStack_98;
        uStack_c0 = uStack_90;
        lStack_d8 = lStack_a8;
        puStack_d0 = puStack_a0;
        (*(code *)&DAT_0ff4b870)(acStack_310,&lStack_d8);
        if (acStack_310[0] == -1) {
          (*(code *)&DAT_04732840)(puStack_298,0x13,1);
          if (puStack_308 == (undefined8 *)0x0) goto code_r0x06de3d90;
        }
        else {
          uStack_348 = uStack_300;
          uStack_340 = uStack_2f8;
          puStack_350 = puStack_308;
          func_0x077d6570(abStack_250,&uStack_f0,auStack_2a0,auStack_358);
          if (abStack_250[0] < 3) {
            if (2 < abStack_250[0]) {
code_r0x06de3d3a:
              func_0x07813660(&lStack_248);
            }
          }
          else if (abStack_250[0] == 3) {
            if (lStack_248 != 0) {
              uVar9 = 1;
code_r0x06de3d8a:
              (*(code *)&DAT_04732840)(uStack_240,lStack_248,uVar9);
            }
          }
          else if (abStack_250[0] == 4) {
            func_0x07c89080(&lStack_248);
            if (lStack_248 != 0) {
              lStack_248 = lStack_248 << 5;
              uVar9 = 8;
              goto code_r0x06de3d8a;
            }
          }
          else if (abStack_250[0] != 0xff) goto code_r0x06de3d3a;
code_r0x06de3d90:
          lVar7 = lStack_108;
          if (lStack_108 == -2) goto code_r0x06de2cf5;
          (*(code *)&DAT_04732870)();
          puVar6 = (undefined8 *)(*(code *)&DAT_04732830)(0x16,1);
          if (puVar6 == (undefined8 *)0x0) {
            (*(code *)&DAT_1208422d)(1,0x16);
code_r0x06de44dd:
            (*(code *)&DAT_1208422d)(1,9);
            pcVar4 = (code *)swi(3);
            puVar6 = (undefined8 *)(*pcVar4)();
            return puVar6;
          }
          *puVar6 = 0x696c696261727564;
          puVar6[1] = 0x6f707369645f7974;
          *(undefined8 *)((long)puVar6 + 0xe) = 0x6e6f697469736f70;
          if ((lVar7 != -1) && (lStack_108 != 0)) {
            (*(code *)&DAT_04732840)(puStack_100,lStack_108,1);
          }
          puStack_f8 = (undefined8 *)0x16;
          lStack_108 = -1;
          puStack_98 = (undefined8 *)0x16;
          lStack_a8 = 0x16;
          puStack_100 = puVar6;
          puStack_a0 = puVar6;
          (*(code *)&DAT_04732870)();
          puVar6 = (undefined8 *)(*(code *)&DAT_04732830)(9,1);
          if (puVar6 == (undefined8 *)0x0) goto code_r0x06de44dd;
          *puVar6 = 0x657474696d6d6f63;
          *(undefined1 *)(puVar6 + 1) = 100;
          lStack_d8 = CONCAT71(lStack_d8._1_7_,3);
          puStack_d0 = (undefined8 *)0x9;
          uStack_c0 = 9;
          puStack_c8 = puVar6;
          func_0x077d6570(&lStack_70,&uStack_f0,&lStack_a8,&lStack_d8);
          if ((byte)lStack_70 < 3) {
            if (2 < (byte)lStack_70) {
code_r0x06de3ec8:
              func_0x07813660(&puStack_68);
            }
          }
          else if ((byte)lStack_70 == 3) {
            if (puStack_68 != (undefined8 *)0x0) {
              uVar9 = 1;
              puVar6 = puStack_68;
code_r0x06de3f06:
              (*(code *)&DAT_04732840)(puStack_60,puVar6,uVar9);
            }
          }
          else if ((byte)lStack_70 == 4) {
            func_0x07c89080(&puStack_68);
            if (puStack_68 != (undefined8 *)0x0) {
              uVar9 = 8;
              puVar6 = (undefined8 *)((long)puStack_68 << 5);
              goto code_r0x06de3f06;
            }
          }
          else if ((byte)lStack_70 != 0xff) goto code_r0x06de3ec8;
          puStack_308 = (undefined8 *)
                        func_0x06e16d30(&lStack_108,*(undefined1 *)(lStack_38 + 0x20e));
          if ((puStack_308 == (undefined8 *)0x0) &&
             ((((cStack_3a == -1 ||
                (puStack_308 = (undefined8 *)func_0x06dc9800(&lStack_108,cStack_3a),
                puStack_308 == (undefined8 *)0x0)) &&
               (puStack_308 = (undefined8 *)
                              func_0x06e1cfa0(&lStack_108,&UNK_006d3f13,0x18,lStack_38 + 0x20a),
               puStack_308 == (undefined8 *)0x0)) &&
              ((puStack_308 = (undefined8 *)
                              func_0x06e1cfa0(&lStack_108,&UNK_0020bdb0,0x10,lStack_38 + 0x20c),
               puStack_308 == (undefined8 *)0x0 &&
               (puStack_308 = (undefined8 *)func_0x06e16990(&lStack_108,lStack_38 + 0x210),
               puStack_308 == (undefined8 *)0x0)))))) {
            puVar6 = &uStack_140;
            uStack_b8 = uStack_e8;
            uStack_b4 = uStack_e4;
            uStack_b0 = (undefined4)uStack_e0;
            uStack_ac = uStack_e0._4_4_;
            puStack_c8 = puStack_f8;
            uStack_c0 = uStack_f0;
            lStack_d8 = lStack_108;
            puStack_d0 = puStack_100;
            (*(code *)&DAT_0ff4b870)(acStack_2f0,&lStack_d8);
            if (acStack_2f0[0] != -1) {
              uStack_328 = uStack_2e0;
              uStack_320 = uStack_2d8;
              puStack_330 = puStack_2e8;
              func_0x077d6570(abStack_230,puVar6,&uStack_288,auStack_338);
              if (abStack_230[0] < 3) {
                if (2 < abStack_230[0]) {
code_r0x06de4098:
                  func_0x07813660(&lStack_228);
                }
              }
              else if (abStack_230[0] == 3) {
                if (lStack_228 != 0) {
                  uVar9 = 1;
code_r0x06de40e8:
                  (*(code *)&DAT_04732840)(uStack_220,lStack_228,uVar9);
                }
              }
              else if (abStack_230[0] == 4) {
                func_0x07c89080(&lStack_228);
                if (lStack_228 != 0) {
                  lStack_228 = lStack_228 << 5;
                  uVar9 = 8;
                  goto code_r0x06de40e8;
                }
              }
              else if (abStack_230[0] != 0xff) goto code_r0x06de4098;
code_r0x06de40ee:
              lVar7 = lStack_158;
              if (lStack_158 != -2) {
                (*(code *)&DAT_04732870)();
                puVar8 = (undefined8 *)(*(code *)&DAT_04732830)(0xe,1);
                if (puVar8 == (undefined8 *)0x0) goto code_r0x06de41e6;
                *(undefined8 *)((long)puVar8 + 6) = 0x676e69646e69625f;
                *puVar8 = 0x625f746e65726170;
                if ((lVar7 != -1) && (lStack_158 != 0)) {
                  (*(code *)&DAT_04732840)(puStack_150,lStack_158,1);
                }
                puStack_148 = (undefined8 *)0xe;
                lStack_158 = -1;
                uStack_168 = 0xe;
                uStack_178 = 0xe;
                lStack_70 = -1;
                uStack_58 = 0;
                uStack_48 = 0;
                puStack_170 = puVar8;
                puStack_150 = puVar8;
                puVar8 = (undefined8 *)
                         func_0x06e2c6a0(&lStack_70,&UNK_006ba113,0x11,lStack_38 + 0x40f);
                if (puVar8 == (undefined8 *)0x0) {
                  if (lStack_70 != -2) goto code_r0x06de41f6;
                  puVar8 = (undefined8 *)(*(code *)&DAT_0ff4ab00)();
                }
                goto code_r0x06de421b;
              }
              goto code_r0x06de2beb;
            }
            (*(code *)&DAT_04732840)(puStack_280,0xe,1);
            puVar8 = puStack_2e8;
            if (puStack_2e8 == (undefined8 *)0x0) goto code_r0x06de40ee;
            goto code_r0x06de2e56;
          }
        }
      }
      else {
        *puVar6 = 0x5f646e616d6d6f63;
        *(undefined4 *)((long)puVar6 + 7) = 0x79656b5f;
        if ((lVar7 != -1) && (lStack_108 != 0)) {
          (*(code *)&DAT_04732840)(puStack_100,lStack_108,1);
        }
        puStack_f8 = (undefined8 *)0xb;
        lStack_108 = -1;
        uStack_190 = 0xb;
        uStack_1a0 = 0xb;
        lStack_70 = -1;
        uStack_58 = 0;
        uStack_48 = 0;
        puStack_198 = puVar6;
        puStack_100 = puVar6;
        puVar6 = (undefined8 *)func_0x06e2c6a0(&lStack_70,&UNK_006d3c6c,0xd,lStack_38 + 0x30);
        if (puVar6 == (undefined8 *)0x0) {
          if (lStack_70 != -2) {
            puVar6 = (undefined8 *)func_0x06e2c6a0(&lStack_70,&UNK_006d3d41,0xf,lStack_38 + 0x40);
            lVar7 = lStack_70;
            if (puVar6 != (undefined8 *)0x0) goto code_r0x06de2e10;
            if (lStack_70 != -2) {
              uStack_180 = (uint)*(byte *)(lStack_38 + 0x50);
              (*(code *)&DAT_04732870)();
              puVar6 = (undefined8 *)(*(code *)&DAT_04732830)(0xc,1);
              if (puVar6 != (undefined8 *)0x0) {
                *puVar6 = 0x5f646e616d6d6f63;
                *(undefined4 *)(puVar6 + 1) = 0x646e696b;
                if ((lVar7 != -1) && (lStack_70 != 0)) {
                  (*(code *)&DAT_04732840)(puStack_68,lStack_70,1);
                }
                puStack_60 = (undefined8 *)0xc;
                lStack_70 = -1;
                uStack_260 = 0xc;
                uStack_270 = 0xc;
                puStack_268 = puVar6;
                puStack_68 = puVar6;
                (*(code *)&DAT_04732870)();
                    /* WARNING: Could not recover jumptable at 0x06de2f49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                puVar6 = (undefined8 *)
                         (*(code *)(&UNK_006d130c + *(int *)(&UNK_006d130c + (ulong)uStack_180 * 4))
                         )();
                return puVar6;
              }
              goto code_r0x06de3b1e;
            }
          }
          puVar6 = (undefined8 *)(*(code *)&DAT_0ff4ab00)();
        }
code_r0x06de2e10:
        func_0x06d08070(&lStack_70);
        uVar9 = 0xb;
        puStack_298 = puStack_198;
code_r0x06de2e28:
        (*(code *)&DAT_04732840)(puStack_298,uVar9,1);
        puStack_308 = puVar6;
      }
code_r0x06de2e33:
      func_0x06d08070(&lStack_108);
      puVar10 = puStack_280;
      puVar8 = puStack_308;
    }
    (*(code *)&DAT_04732840)(puVar10,0xe,1);
  }
code_r0x06de2e56:
  func_0x06d08070(&lStack_158);
  puStack_68 = puVar8;
joined_r0x06de444f:
  if (pauStack_210 != (undefined1 (*) [16])0x0) {
    (*(code *)&DAT_04732840)(lStack_208,pauStack_210,1);
  }
                    /* WARNING: Read-only address (ram,0x00213e40) is written */
                    /* WARNING: Read-only address (ram,0x002212f0) is written */
  return puStack_68;
}

