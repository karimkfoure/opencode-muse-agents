
undefined8 worktree_resolve(long *param_1,long param_2,long param_3,int *param_4)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long *plVar7;
  long lVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  long extraout_RDX;
  long *plVar11;
  undefined1 uVar12;
  long lStack_170;
  long lStack_168;
  undefined4 *puStack_160;
  undefined1 auStack_158 [8];
  undefined8 uStack_150;
  undefined4 *puStack_148;
  undefined8 uStack_140;
  undefined8 uStack_134;
  undefined1 uStack_12c;
  byte abStack_128 [8];
  long lStack_120;
  undefined8 uStack_118;
  int *piStack_108;
  long lStack_100;
  long lStack_c0;
  long lStack_b8;
  long lStack_b0;
  char acStack_a8 [9];
  undefined4 uStack_9f;
  undefined2 uStack_9b;
  undefined1 uStack_99;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  byte abStack_80 [8];
  long lStack_78;
  undefined8 uStack_70;
  int *piStack_60;
  long lStack_58;
  char acStack_50 [8];
  undefined1 uStack_48;
  undefined4 uStack_47;
  undefined2 uStack_43;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  lVar1 = *param_1;
  if (lVar1 == -2) {
    plVar11 = (long *)&UNK_006d32dc;
    lVar8 = 0x28;
    (*(code *)&DAT_1208f3b0)(&UNK_006d32dc,0x28,&UNK_12138800);
    lVar1 = *plVar11;
    if (lVar1 == -2) {
      (*(code *)&DAT_1208f3b0)(&UNK_006d32dc,0x28,&UNK_12138800);
code_r0x06e28759:
      (*(code *)&DAT_1208422d)(1,0x24);
      pcVar2 = (code *)swi(3);
      uVar10 = (*pcVar2)();
      return uVar10;
    }
    uVar12 = extraout_RDX == 0;
    if (-1 < extraout_RDX) goto code_r0x06e28595;
    plVar7 = (long *)0x0;
    do {
      plVar11 = plVar7;
      uVar12 = 1;
      lVar8 = extraout_RDX;
      (*(code *)&DAT_1208422d)();
code_r0x06e28595:
      if ((bool)uVar12) {
        lVar8 = 1;
        goto joined_r0x06e285ed;
      }
      piStack_108 = param_4;
      lStack_100 = lVar8;
      (*(code *)&DAT_04732870)();
      lVar8 = (*(code *)&DAT_04732830)(extraout_RDX,1);
      plVar7 = (long *)0x1;
    } while (lVar8 == 0);
    (*(code *)&DAT_120cba68)(lVar8,lStack_100,extraout_RDX);
    param_4 = piStack_108;
joined_r0x06e285ed:
    if ((lVar1 != -1) && (lVar1 != 0)) {
      (*(code *)&DAT_04732840)(plVar11[1],lVar1,1);
    }
    plVar11[1] = lVar8;
    plVar11[2] = extraout_RDX;
    *plVar11 = -1;
    lStack_168 = plVar11[1];
    puStack_148 = (undefined4 *)plVar11[2];
    lStack_170 = extraout_RDX;
    puStack_160 = puStack_148;
    if ((char)*param_4 == '\x01') {
      uStack_12c = 0;
      uStack_134 = 0;
      puVar9 = (undefined4 *)func_0x06c61450((char *)((long)param_4 + 1),auStack_158);
      (*(code *)&DAT_04732870)();
      puStack_148 = (undefined4 *)(*(code *)&DAT_04732830)(0x24,1);
      if (puStack_148 == (undefined4 *)0x0) goto code_r0x06e28759;
      puStack_148[8] = puVar9[8];
      uVar3 = *puVar9;
      uVar4 = puVar9[1];
      uVar5 = puVar9[2];
      uVar6 = puVar9[3];
      uVar10 = *(undefined8 *)(puVar9 + 6);
      *(undefined8 *)(puStack_148 + 4) = *(undefined8 *)(puVar9 + 4);
      *(undefined8 *)(puStack_148 + 6) = uVar10;
      *puStack_148 = uVar3;
      puStack_148[1] = uVar4;
      puStack_148[2] = uVar5;
      puStack_148[3] = uVar6;
      auStack_158[0] = 3;
    }
    else {
      auStack_158[0] = 0;
    }
    uStack_150 = 0x24;
    uStack_140 = 0x24;
    bind_validator(abStack_128,plVar11 + 3,&lStack_170,auStack_158);
    if (abStack_128[0] < 3) {
      if (abStack_128[0] < 3) {
        return 0;
      }
code_r0x06e286eb:
      record_release(&lStack_120);
    }
    else {
      if (abStack_128[0] == 3) {
        if (lStack_120 == 0) {
          return 0;
        }
        uVar10 = 1;
      }
      else {
        if (abStack_128[0] != 4) {
          if (abStack_128[0] == 0xff) {
            return 0;
          }
          goto code_r0x06e286eb;
        }
        func_0x07c89080(&lStack_120);
        if (lStack_120 == 0) {
          return 0;
        }
        lStack_120 = lStack_120 << 5;
        uVar10 = 8;
      }
      (*(code *)&DAT_04732840)(uStack_118,lStack_120,uVar10);
    }
    return 0;
  }
  uVar12 = param_3 == 0;
  if (-1 < param_3) goto code_r0x06e28388;
  plVar11 = (long *)0x0;
  do {
    param_1 = plVar11;
    uVar12 = 1;
    param_2 = param_3;
    (*(code *)&DAT_1208422d)();
code_r0x06e28388:
    if ((bool)uVar12) {
      lVar8 = 1;
      goto joined_r0x06e283e0;
    }
    piStack_60 = param_4;
    lStack_58 = param_2;
    (*(code *)&DAT_04732870)();
    lVar8 = (*(code *)&DAT_04732830)(param_3,1);
    plVar11 = (long *)0x1;
  } while (lVar8 == 0);
  (*(code *)&DAT_120cba68)(lVar8,lStack_58,param_3);
  param_4 = piStack_60;
joined_r0x06e283e0:
  if ((lVar1 != -1) && (lVar1 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar1,1);
  }
  param_1[1] = lVar8;
  param_1[2] = param_3;
  *param_1 = -1;
  lStack_b8 = param_1[1];
  lStack_b0 = param_1[2];
  lStack_c0 = param_3;
  if (*param_4 == 2) {
    acStack_50[0] = '\0';
  }
  else {
    func_0x05a13510(acStack_50,param_4);
    if (acStack_50[0] == -1) {
      uVar10 = CONCAT17(uStack_41,CONCAT25(uStack_43,CONCAT41(uStack_47,uStack_48)));
      if (param_3 == 0) {
        return uVar10;
      }
      (*(code *)&DAT_04732840)(lStack_b8,param_3,1);
      return uVar10;
    }
  }
  uStack_98 = uStack_40;
  uStack_94 = uStack_3c;
  uStack_90 = uStack_38;
  uStack_8c = uStack_34;
  acStack_a8[0] = acStack_50[0];
  uStack_9f = uStack_47;
  uStack_9b = uStack_43;
  uStack_99 = uStack_41;
  bind_validator(abStack_80,param_1 + 3,&lStack_c0,acStack_a8);
  if (abStack_80[0] < 3) {
    if (abStack_80[0] < 3) {
      return 0;
    }
code_r0x06e284c9:
    record_release(&lStack_78);
  }
  else {
    if (abStack_80[0] == 3) {
      if (lStack_78 == 0) {
        return 0;
      }
      uVar10 = 1;
    }
    else {
      if (abStack_80[0] != 4) {
        if (abStack_80[0] == 0xff) {
          return 0;
        }
        goto code_r0x06e284c9;
      }
      func_0x07c89080(&lStack_78);
      if (lStack_78 == 0) {
        return 0;
      }
      lStack_78 = lStack_78 << 5;
      uVar10 = 8;
    }
    (*(code *)&DAT_04732840)(uStack_70,lStack_78,uVar10);
  }
  return 0;
}

