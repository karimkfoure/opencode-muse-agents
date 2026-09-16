
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void subagent_spawn_validate
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,long *param_6,undefined8 param_7)

{
  code *pcVar1;
  long lVar2;
  undefined8 *******pppppppuVar3;
  undefined8 *puVar4;
  undefined8 *******pppppppuVar5;
  undefined8 *******pppppppuVar6;
  undefined8 *******pppppppuVar7;
  byte bVar8;
  undefined8 uVar9;
  bool bVar10;
  undefined1 auVar11 [16];
  undefined1 auStack_288 [8];
  long *plStack_280;
  long lStack_278;
  long lStack_270;
  undefined1 (*pauStack_268) [16];
  long lStack_260;
  long lStack_258;
  undefined1 (*pauStack_250) [16];
  long lStack_248;
  long lStack_240;
  undefined *puStack_238;
  undefined8 uStack_230;
  undefined8 *******pppppppuStack_228;
  undefined8 uStack_220;
  undefined8 *******pppppppuStack_218;
  undefined8 ******ppppppuStack_1e0;
  undefined8 uStack_1d8;
  undefined8 *puStack_1d0;
  undefined8 *******pppppppuStack_1c8;
  undefined8 *******pppppppuStack_1c0;
  undefined8 *******pppppppuStack_1b8;
  undefined8 *******pppppppuStack_1b0;
  undefined8 *******pppppppuStack_1a8;
  undefined8 *******pppppppuStack_1a0;
  undefined *puStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  long lStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  long lStack_b0;
  undefined8 *******pppppppuStack_a8;
  undefined8 uStack_a0;
  undefined8 *******pppppppuStack_98;
  undefined8 *******pppppppuStack_90;
  undefined8 *******pppppppuStack_88;
  undefined8 *******pppppppuStack_80;
  undefined8 uStack_78;
  undefined8 *puStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long *plStack_58;
  undefined8 *******pppppppuStack_50;
  undefined8 *******pppppppuStack_48;
  undefined8 *******pppppppuStack_40;
  undefined8 *******pppppppuStack_38;
  
  uStack_1d8 = param_5;
  func_0x07501da0(&pppppppuStack_1b0,param_3,param_4);
  if (pppppppuStack_1b0 == (undefined8 *******)0xffffffffffffffff) {
    (*(code *)&DAT_04732870)();
    lVar2 = (*(code *)&DAT_04732830)(0x30,8);
    if (lVar2 != 0) {
      func_0x0757ca40(lVar2,6,&UNK_006fcd39,0x11,param_7);
      *param_1 = 2;
      param_1[1] = &UNK_0038ba4d;
      param_1[2] = 10;
      *(undefined4 *)(param_1 + 3) = 0x13;
      *(undefined4 *)((long)param_1 + 0x1c) = 0x10;
      *(undefined1 *)(param_1 + 0x11) = 0;
      param_1[0xb] = 1;
      param_1[0xc] = lVar2;
      param_1[0xd] = 1;
      param_1[0xe] = 0;
      param_1[0xf] = 8;
      param_1[0x10] = 0;
      goto code_r0x0759a027;
    }
code_r0x0759a1b9:
    (*(code *)&DAT_12088f47)(8,0x30);
code_r0x0759a1c9:
    (*(code *)&DAT_1208422d)(pppppppuStack_a8,pppppppuStack_1a0);
code_r0x0759a1dd:
    (*(code *)&DAT_1208422d)(1,0x1c);
code_r0x0759a1ed:
    (*(code *)&DAT_1208422d)(1,0x22);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  plStack_58 = param_6;
  (*(code *)&DAT_120cba68)(auStack_288,&pppppppuStack_1b0,0xa8);
  if ((lStack_278 == 8) &&
     (((*plStack_280 == 0x6465747065636361 ||
       (((*plStack_280 == 0x6465727265666564 && (lStack_270 == -1)) &&
        ((lStack_258 == -1 ||
         ((lStack_248 == 0xe &&
          (*(long *)(*pauStack_250 + 6) == 0x65756575715f7974 &&
           *(long *)*pauStack_250 == 0x7974696361706163)))))))) &&
      (pppppppuStack_228 != (undefined8 *******)0xffffffffffffffff)))) {
    *param_1 = 2;
    param_1[1] = &UNK_0038ba4d;
    param_1[2] = 10;
    *(undefined4 *)(param_1 + 3) = 0x1e;
    *(undefined4 *)((long)param_1 + 0x1c) = 0x10;
    *(undefined1 *)(param_1 + 0x11) = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 8;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 8;
    param_1[0x10] = 0;
    func_0x07367210(auStack_288);
    param_6 = plStack_58;
    goto code_r0x0759a027;
  }
  puStack_1d0 = param_1;
  func_0x0759b110(&lStack_c8,param_2,&UNK_006fc0d5,9);
  pppppppuStack_50 = pppppppuStack_218;
  uStack_60 = 0;
  if (pppppppuStack_228 != (undefined8 *******)0xffffffffffffffff) {
    uStack_60 = uStack_220;
  }
  pppppppuVar6 = (undefined8 *******)0x4;
  func_0x0759b110(&pppppppuStack_1b0,param_2,&UNK_002690fc);
  if (pppppppuStack_1b0 == (undefined8 *******)0xffffffffffffffff) {
    pppppppuVar6 = (undefined8 *******)0xa;
    func_0x0759b110(&pppppppuStack_48,param_2,&UNK_006fc0c6);
    if (pppppppuStack_48 == (undefined8 *******)0xffffffffffffffff) goto code_r0x0759945b;
code_r0x0759940c:
    pppppppuVar3 = pppppppuStack_40;
    pppppppuVar5 = pppppppuStack_48;
    pppppppuVar6 = (undefined8 *******)0x20;
    func_0x07532ce0(&pppppppuStack_1b0,pppppppuStack_40,pppppppuStack_38);
    if (pppppppuVar5 != (undefined8 *******)0x0) {
      (*(code *)&DAT_04732840)(pppppppuVar3,pppppppuVar5,1);
    }
    pppppppuVar5 = pppppppuStack_1a0;
    pppppppuVar3 = pppppppuStack_1a8;
    pppppppuVar7 = pppppppuStack_1b0;
    if (pppppppuStack_1b0 == (undefined8 *******)0xffffffffffffffff) goto code_r0x0759945b;
    goto code_r0x075994c8;
  }
  pppppppuStack_38 = pppppppuStack_1a0;
  pppppppuStack_48 = pppppppuStack_1b0;
  pppppppuStack_40 = pppppppuStack_1a8;
  if (pppppppuStack_1b0 != (undefined8 *******)0xffffffffffffffff) goto code_r0x0759940c;
code_r0x0759945b:
  pppppppuVar5 = pppppppuStack_50;
  if (pppppppuStack_228 == (undefined8 *******)0xffffffffffffffff) {
code_r0x07599479:
    pppppppuVar5 = pppppppuVar6;
    pppppppuVar3 = pppppppuStack_228;
    pppppppuVar7 = (undefined8 *******)0xffffffffffffffff;
  }
  else {
    if ((long)pppppppuStack_50 < 0) {
      uVar9 = 0;
code_r0x0759946d:
      (*(code *)&DAT_1208422d)(uVar9,pppppppuVar5);
      goto code_r0x07599479;
    }
    if (pppppppuStack_50 == (undefined8 *******)0x0) {
      pppppppuVar3 = (undefined8 *******)0x1;
      pppppppuVar5 = (undefined8 *******)0x0;
      pppppppuVar7 = (undefined8 *******)0x0;
    }
    else {
      (*(code *)&DAT_04732870)();
      uVar9 = 1;
      pppppppuVar3 = (undefined8 *******)(*(code *)&DAT_04732830)(pppppppuVar5,1);
      if (pppppppuVar3 == (undefined8 *******)0x0) goto code_r0x0759946d;
      (*(code *)&DAT_120cba68)(pppppppuVar3,uStack_220,pppppppuVar5);
      pppppppuVar7 = pppppppuVar5;
    }
  }
code_r0x075994c8:
  pppppppuStack_1c8 = pppppppuVar7;
  pppppppuStack_1c0 = pppppppuVar3;
  if (lStack_278 == 8) {
    if (*plStack_280 == 0x6465747065636361) {
      (*(code *)&DAT_04732870)();
      puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(0x30,8);
      if (puStack_70 == (undefined8 *)0x0) goto code_r0x0759a1b9;
      pppppppuVar6 = (undefined8 *******)0x0;
      if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
        pppppppuVar6 = pppppppuVar3;
      }
      func_0x0759ab80(&pppppppuStack_1b0,&UNK_006fd016,0xc,pppppppuVar6,pppppppuVar5,uStack_60,
                      pppppppuStack_50);
      pppppppuVar6 = pppppppuStack_1a8;
      func_0x0757ca40(puStack_70,1,pppppppuStack_1a8,pppppppuStack_1a0,param_7);
      uStack_78 = 1;
      uStack_68 = 1;
      pppppppuVar5 = pppppppuStack_1b0;
    }
    else {
      if (*plStack_280 == 0x6465727265666564) {
        if (lStack_270 == -1) {
          if (lStack_258 == -1) {
code_r0x07599a09:
            pppppppuVar6 = (undefined8 *******)0x0;
            if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
              pppppppuVar6 = pppppppuVar3;
            }
            if (*plStack_58 == 1) {
              ppppppuStack_1e0 = (undefined8 ******)plStack_58[1];
              pppppppuStack_98 = (undefined8 *******)plStack_58[2];
              pppppppuStack_1b0 = &ppppppuStack_1e0;
              pppppppuStack_1a8 = (undefined8 *******)&DAT_120a3e30;
              pppppppuStack_1a0 = &pppppppuStack_98;
              puStack_198 = &DAT_120a3e30;
              pppppppuStack_80 = pppppppuVar5;
              (*(code *)&DAT_12089060)(&pppppppuStack_48,&UNK_002f35d5,&pppppppuStack_1b0);
            }
            else {
              pppppppuStack_80 = pppppppuVar5;
              (*(code *)&DAT_04732870)();
              pppppppuVar5 = (undefined8 *******)(*(code *)&DAT_04732830)(0x22,1);
              if (pppppppuVar5 == (undefined8 *******)0x0) goto code_r0x0759a1ed;
              pppppppuVar5[2] = (undefined8 ******)0x20676e6974696177;
              pppppppuVar5[3] = (undefined8 ******)0x6c73206120726f66;
              *pppppppuVar5 = (undefined8 ******)0x7571206e77617053;
              pppppppuVar5[1] = (undefined8 ******)0x20b7c22064657565;
              *(undefined2 *)(pppppppuVar5 + 4) = 0x746f;
              pppppppuStack_48 = (undefined8 *******)0x22;
              pppppppuStack_38 = (undefined8 *******)0x22;
              pppppppuStack_40 = pppppppuVar5;
            }
            (*(code *)&DAT_04732870)();
            puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(0x30,8);
            pppppppuVar5 = pppppppuStack_50;
            if (puStack_70 == (undefined8 *)0x0) goto code_r0x0759a1b9;
            pppppppuStack_50 = pppppppuStack_40;
            func_0x0759ab80(&pppppppuStack_1b0,pppppppuStack_40,pppppppuStack_38,pppppppuVar6,
                            pppppppuStack_80,uStack_60,pppppppuVar5);
            pppppppuVar3 = pppppppuStack_1a8;
            func_0x0757ca40(puStack_70,1,pppppppuStack_1a8,pppppppuStack_1a0,param_7);
            uStack_78 = 1;
            uStack_68 = 1;
            pppppppuVar6 = pppppppuStack_50;
            pppppppuVar5 = pppppppuStack_48;
            if (pppppppuStack_1b0 != (undefined8 *******)0x0) {
              (*(code *)&DAT_04732840)(pppppppuVar3,pppppppuStack_1b0,1);
              pppppppuVar6 = pppppppuStack_50;
              pppppppuVar5 = pppppppuStack_48;
            }
            goto joined_r0x0759a1a5;
          }
          bVar10 = true;
          if (lStack_248 != 0xe) goto code_r0x07599929;
          if (*(long *)(*pauStack_250 + 6) == 0x65756575715f7974 &&
              *(long *)*pauStack_250 == 0x7974696361706163) goto code_r0x07599a09;
          goto code_r0x07599d55;
        }
        bVar10 = lStack_258 != -1;
code_r0x07599929:
        if (((bVar10) && (lStack_248 == 0x12)) &&
           (ZEXT216(*(ushort *)pauStack_250[1]) == _UNK_0021ca10 && *pauStack_250 == _UNK_0021bd90))
        goto code_r0x0759a075;
        if (lStack_270 != -1) {
          if (lStack_260 == 0x1a) {
            if (*pauStack_268 == _UNK_0021f2d0 &&
                *(undefined1 (*) [16])(*pauStack_268 + 10) == _UNK_0020b0f0) goto code_r0x0759a075;
          }
          else if ((lStack_260 == 0x12) &&
                  (ZEXT216(*(ushort *)pauStack_268[1]) == _UNK_0021ca10 &&
                   *pauStack_268 == _UNK_002227f0)) {
code_r0x0759a075:
            pppppppuVar6 = (undefined8 *******)0x0;
            if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
              pppppppuVar6 = pppppppuVar3;
            }
            func_0x0759a680(&uStack_78,auStack_288,pppppppuVar6);
            goto code_r0x07599ea3;
          }
        }
code_r0x07599d55:
        pppppppuStack_80 = pppppppuVar5;
        puVar4 = (undefined8 *)func_0x075355f0(0x30);
        func_0x075090f0(&pppppppuStack_1b0,auStack_288);
        pppppppuStack_90 = (undefined8 *******)&UNK_075f48c0;
        pppppppuStack_98 = &pppppppuStack_1b0;
        func_0x07535560(&pppppppuStack_48,&UNK_002ce522,&pppppppuStack_98);
        if (pppppppuStack_1b0 != (undefined8 *******)0x0) {
          (*(code *)&DAT_04732840)(pppppppuStack_1a8,pppppppuStack_1b0,1);
        }
        pppppppuVar6 = pppppppuStack_40;
        pppppppuVar5 = (undefined8 *******)0x0;
        if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
          pppppppuVar5 = pppppppuVar3;
        }
        func_0x0759ab80(&pppppppuStack_98,pppppppuStack_40,pppppppuStack_38,pppppppuVar5,
                        pppppppuStack_80,uStack_60,pppppppuStack_50);
        pppppppuVar3 = pppppppuStack_90;
        func_0x0757ca40(&pppppppuStack_1b0,1,pppppppuStack_90,pppppppuStack_88,param_7);
        puVar4[4] = uStack_190;
        puVar4[5] = uStack_188;
        puVar4[2] = pppppppuStack_1a0;
        puVar4[3] = puStack_198;
        *puVar4 = pppppppuStack_1b0;
        puVar4[1] = pppppppuStack_1a8;
        pppppppuVar7 = pppppppuStack_98;
        puStack_70 = puVar4;
      }
      else {
        if (*plStack_280 != 0x64657463656a6572) goto code_r0x07599778;
        pppppppuStack_1b8 = (undefined8 *******)0x0;
        if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
          pppppppuStack_1b8 = pppppppuVar3;
        }
        lStack_b0 = lStack_258;
        pppppppuStack_80 = pppppppuVar5;
        if (((lStack_258 != -1) &&
            (auVar11 = error_message_lookup(pauStack_250,lStack_248), auVar11._0_8_ != 0)) ||
           ((lStack_270 != -1 &&
            (auVar11 = error_message_lookup(pauStack_268,lStack_260), auVar11._0_8_ != 0)))) {
          pppppppuVar5 = auVar11._8_8_;
          uStack_a0 = auVar11._0_8_;
          func_0x064d5bf0(&pppppppuStack_1b0,pppppppuVar5,0,1,1);
          pppppppuVar6 = pppppppuStack_1a0;
          pppppppuStack_a8 = pppppppuStack_1a8;
          if ((int)pppppppuStack_1b0 != 1) {
            (*(code *)&DAT_120cba68)(pppppppuStack_1a0,uStack_a0,pppppppuVar5);
            pppppppuStack_90 = pppppppuVar6;
            pppppppuStack_88 = pppppppuVar5;
            pppppppuVar5 = pppppppuStack_a8;
            goto code_r0x07599675;
          }
          goto code_r0x0759a1c9;
        }
        if (lStack_258 != -1) {
          func_0x072d74f0(&pppppppuStack_1b0,pauStack_250,lStack_248,0x2d0000005f);
          pppppppuVar6 = pppppppuStack_1a8;
          func_0x0759aa20(&pppppppuStack_98,pppppppuStack_1a8,pppppppuStack_1a0);
          if (pppppppuStack_1b0 != (undefined8 *******)0x0) {
            (*(code *)&DAT_04732840)(pppppppuVar6,pppppppuStack_1b0,1);
          }
          pppppppuVar5 = pppppppuStack_98;
          pppppppuVar6 = pppppppuStack_90;
          if (pppppppuStack_98 != (undefined8 *******)0xffffffffffffffff) goto code_r0x07599675;
        }
        if (lStack_270 == -1) {
code_r0x07599b92:
          (*(code *)&DAT_04732870)();
          pppppppuVar6 = (undefined8 *******)(*(code *)&DAT_04732830)(0x1c,1);
          if (pppppppuVar6 != (undefined8 *******)0x0) {
            *(undefined8 *)((long)pppppppuVar6 + 0xc) = 0x20746f6e20736177;
            *(undefined8 *)((long)pppppppuVar6 + 0x14) = 0x64657474696d6461;
            *pppppppuVar6 = (undefined8 ******)0x7571657220656874;
            pppppppuVar6[1] = (undefined8 ******)0x2073617720747365;
            pppppppuStack_1b0 = (undefined8 *******)0x1c;
            pppppppuStack_1a0 = (undefined8 *******)0x1c;
            lVar2 = lStack_258;
            pppppppuVar5 = pppppppuStack_1b0;
            pppppppuVar3 = pppppppuStack_1a0;
            goto code_r0x07599be5;
          }
          goto code_r0x0759a1dd;
        }
        func_0x072d74f0(&pppppppuStack_1b0,pauStack_268,lStack_260,0x2d0000005f);
        pppppppuVar3 = pppppppuStack_1a8;
        func_0x0759aa20(&pppppppuStack_48,pppppppuStack_1a8,pppppppuStack_1a0);
        pppppppuStack_88 = pppppppuStack_38;
        pppppppuVar5 = pppppppuStack_48;
        pppppppuVar6 = pppppppuStack_40;
        if (pppppppuStack_1b0 != (undefined8 *******)0x0) {
          (*(code *)&DAT_04732840)(pppppppuVar3,pppppppuStack_1b0,1);
          pppppppuStack_88 = pppppppuStack_38;
          pppppppuVar5 = pppppppuStack_48;
          pppppppuVar6 = pppppppuStack_40;
        }
code_r0x07599675:
        lVar2 = lStack_b0;
        pppppppuVar3 = pppppppuStack_88;
        if (pppppppuStack_88 == (undefined8 *******)0x0) {
          lStack_258 = lStack_b0;
          if (pppppppuVar5 != (undefined8 *******)0x0) {
            (*(code *)&DAT_04732840)(pppppppuVar6,pppppppuVar5,1);
          }
          goto code_r0x07599b92;
        }
code_r0x07599be5:
        pppppppuStack_1a0 = pppppppuVar3;
        pppppppuStack_1a8 = pppppppuVar6;
        pppppppuStack_1b0 = pppppppuVar5;
        pppppppuStack_98 = &pppppppuStack_1b0;
        pppppppuStack_90 = (undefined8 *******)&UNK_075f48c0;
        (*(code *)&DAT_12089060)(&pppppppuStack_48,&UNK_00336667,&pppppppuStack_98);
        if (pppppppuStack_1b0 != (undefined8 *******)0x0) {
          (*(code *)&DAT_04732840)(pppppppuStack_1a8,pppppppuStack_1b0,1);
        }
        if (((lVar2 == -1) || (lStack_248 != 0x14)) ||
           (*pauStack_250 != _UNK_00204430 || ZEXT416(*(uint *)pauStack_250[1]) != _UNK_0021cf00)) {
          if (lStack_240 == -1) {
            puStack_238 = (undefined *)0x0;
          }
        }
        else {
          puStack_238 = &UNK_006fd022;
          uStack_230 = 0x80;
        }
        func_0x0759a580(&pppppppuStack_48,puStack_238,uStack_230);
        (*(code *)&DAT_04732870)();
        puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(0x30,8);
        pppppppuVar6 = pppppppuStack_40;
        if (puStack_70 == (undefined8 *)0x0) goto code_r0x0759a1b9;
        func_0x0759ab80(&pppppppuStack_1b0,pppppppuStack_40,pppppppuStack_38,pppppppuStack_1b8,
                        pppppppuStack_80,uStack_60,pppppppuStack_50);
        pppppppuVar3 = pppppppuStack_1a8;
        func_0x0757ca40(puStack_70,6,pppppppuStack_1a8,pppppppuStack_1a0,param_7);
        pppppppuVar7 = pppppppuStack_1b0;
      }
      uStack_68 = 1;
      uStack_78 = 1;
      pppppppuVar5 = pppppppuStack_48;
      if (pppppppuVar7 != (undefined8 *******)0x0) {
        (*(code *)&DAT_04732840)(pppppppuVar3,pppppppuVar7,1);
        pppppppuVar5 = pppppppuStack_48;
      }
    }
joined_r0x0759a1a5:
    if (pppppppuVar5 != (undefined8 *******)0x0) {
      (*(code *)&DAT_04732840)(pppppppuVar6,pppppppuVar5,1);
    }
code_r0x07599ea3:
    pppppppuStack_38 = (undefined8 *******)0x0;
    pppppppuStack_40 = (undefined8 *******)0x8;
    pppppppuStack_48 = (undefined8 *******)0x0;
    param_6 = plStack_58;
    if ((*plStack_280 == 0x6465747065636361) || (*plStack_280 == 0x6465727265666564)) {
code_r0x07599efd:
      pppppppuStack_38 = (undefined8 *******)0x0;
      pppppppuStack_40 = (undefined8 *******)0x8;
      pppppppuStack_48 = (undefined8 *******)0x0;
      if (lStack_c8 == -1) {
        bVar8 = 1;
        goto code_r0x07599f75;
      }
    }
    else {
      bVar8 = 1;
      if (lStack_c8 == -1 || *plStack_280 != 0x64657463656a6572) goto code_r0x07599f75;
    }
code_r0x07599f03:
    uVar9 = uStack_c0;
    lVar2 = lStack_c8;
    pppppppuStack_38 = (undefined8 *******)0x0;
    pppppppuStack_40 = (undefined8 *******)0x8;
    pppppppuStack_48 = (undefined8 *******)0x0;
    func_0x0759b6f0(&pppppppuStack_1b0,uStack_c0,uStack_b8,uStack_1d8,4,param_7);
    (*(code *)&DAT_064d46a0)(&pppppppuStack_48);
    (*(code *)&DAT_120cba68)(pppppppuStack_40,&pppppppuStack_1b0,0xe8);
    pppppppuStack_38 = (undefined8 *******)0x1;
    if (lVar2 != 0) {
      (*(code *)&DAT_04732840)(uVar9,lVar2,1);
    }
    bVar8 = 0;
  }
  else {
    if (lStack_278 != 9) {
code_r0x07599778:
      (*(code *)&DAT_04732870)();
      puVar4 = (undefined8 *)(*(code *)&DAT_04732830)(0x30,8);
      if (puVar4 == (undefined8 *)0x0) goto code_r0x0759a1b9;
      func_0x0757ca40(puVar4,6,&UNK_006fcd39,0x11,param_7);
      uStack_78 = 1;
      uStack_68 = 1;
      pppppppuStack_48 = (undefined8 *******)0x0;
      pppppppuStack_40 = (undefined8 *******)0x8;
      pppppppuStack_38 = (undefined8 *******)0x0;
      puStack_70 = puVar4;
      if (lStack_278 != 8) {
        bVar8 = 1;
        param_6 = plStack_58;
        if (lStack_278 == 9) goto code_r0x075997fd;
        goto code_r0x07599f75;
      }
      goto code_r0x07599ea3;
    }
    if ((char)plStack_280[1] == 'e' && *plStack_280 == 0x746163696c707564) {
      if (lStack_c8 == -1) goto code_r0x07599778;
      (*(code *)&DAT_04732870)();
      puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(0x30,8);
      if (puStack_70 == (undefined8 *)0x0) goto code_r0x0759a1b9;
      pppppppuVar6 = (undefined8 *******)0x0;
      if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
        pppppppuVar6 = pppppppuVar3;
      }
      func_0x0759ab80(&pppppppuStack_1b0,&UNK_006fcd23,0x16,pppppppuVar6,pppppppuVar5,uStack_60,
                      pppppppuStack_50);
      pppppppuVar6 = pppppppuStack_1a8;
      func_0x0757ca40(puStack_70,1,pppppppuStack_1a8,pppppppuStack_1a0,param_7);
      param_6 = plStack_58;
      uStack_78 = 1;
      uStack_68 = 1;
      if (pppppppuStack_1b0 != (undefined8 *******)0x0) {
        (*(code *)&DAT_04732840)(pppppppuVar6,pppppppuStack_1b0,1);
      }
    }
    else {
      if ((char)plStack_280[1] != 'y' || *plStack_280 != 0x646165725f746f6e) goto code_r0x07599778;
      pppppppuVar6 = (undefined8 *******)0x0;
      if (pppppppuVar7 != (undefined8 *******)0xffffffffffffffff) {
        pppppppuVar6 = pppppppuVar3;
      }
      func_0x0759a680(&uStack_78,auStack_288,pppppppuVar6);
      param_6 = plStack_58;
    }
code_r0x075997fd:
    pppppppuStack_38 = (undefined8 *******)0x0;
    pppppppuStack_40 = (undefined8 *******)0x8;
    pppppppuStack_48 = (undefined8 *******)0x0;
    if ((char)plStack_280[1] == 'e' && *plStack_280 == 0x746163696c707564) goto code_r0x07599efd;
    bVar8 = 1;
    if (lStack_c8 != -1 && ((char)plStack_280[1] == 'y' && *plStack_280 == 0x646165725f746f6e))
    goto code_r0x07599f03;
  }
code_r0x07599f75:
  puStack_1d0[0x10] = pppppppuStack_38;
  puStack_1d0[0xe] = pppppppuStack_48;
  puStack_1d0[0xf] = pppppppuStack_40;
  *puStack_1d0 = 2;
  puStack_1d0[1] = &UNK_0038ba4d;
  puStack_1d0[2] = 10;
  puStack_1d0[3] = 0x50000004d;
  *(undefined1 *)(puStack_1d0 + 0x11) = 0;
  puStack_1d0[0xb] = uStack_78;
  puStack_1d0[0xc] = puStack_70;
  puStack_1d0[0xd] = uStack_68;
  if ((undefined *)((long)pppppppuStack_1c8 + -1) < (undefined *)0xfffffffffffffffe) {
    (*(code *)&DAT_04732840)(pppppppuStack_1c0,pppppppuStack_1c8,1);
  }
  if (((bool)(bVar8 & lStack_c8 != -1)) && (lStack_c8 != 0)) {
    (*(code *)&DAT_04732840)(uStack_c0,lStack_c8,1);
  }
  func_0x07367210(auStack_288);
code_r0x0759a027:
  lVar2 = param_6[3];
  if ((lVar2 != -1) && (lVar2 != 0)) {
    (*(code *)&DAT_04732840)(param_6[4],lVar2,1);
  }
  lVar2 = param_6[6];
  if ((lVar2 != -1) && (lVar2 != 0)) {
    (*(code *)&DAT_04732840)(param_6[7],lVar2,1);
  }
  return;
}

