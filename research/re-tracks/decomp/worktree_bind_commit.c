
undefined8 worktree_bind_commit(long *param_1,long param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  long *plVar10;
  long lVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  undefined1 uVar14;
  long lStack_a8;
  long lStack_a0;
  long lStack_98;
  undefined1 auStack_90 [8];
  undefined8 uStack_88;
  undefined4 *puStack_80;
  undefined8 uStack_78;
  undefined8 uStack_6c;
  undefined1 uStack_64;
  byte abStack_60 [8];
  long lStack_58;
  undefined8 uStack_50;
  undefined8 uStack_40;
  long lStack_38;
  
  lVar1 = *param_1;
  if (lVar1 == -2) {
    (*(code *)&DAT_1208f3b0)(&UNK_006d32dc,0x28,&UNK_12138800);
code_r0x06e2c88b:
    (*(code *)&DAT_1208422d)(1,0x24);
    pcVar2 = (code *)swi(3);
    uVar13 = (*pcVar2)();
    return uVar13;
  }
  uVar14 = param_3 == 0;
  if (-1 < param_3) goto code_r0x06e2c6d5;
  plVar10 = (long *)0x0;
  do {
    param_1 = plVar10;
    uVar14 = 1;
    param_2 = param_3;
    (*(code *)&DAT_1208422d)();
code_r0x06e2c6d5:
    if ((bool)uVar14) {
      lVar11 = 1;
      goto joined_r0x06e2c72d;
    }
    uStack_40 = param_4;
    lStack_38 = param_2;
    (*(code *)&DAT_04732870)();
    lVar11 = (*(code *)&DAT_04732830)(param_3,1);
    plVar10 = (long *)0x1;
  } while (lVar11 == 0);
  (*(code *)&DAT_120cba68)(lVar11,lStack_38,param_3);
  param_4 = uStack_40;
joined_r0x06e2c72d:
  if ((lVar1 != -1) && (lVar1 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar1,1);
  }
  param_1[1] = lVar11;
  param_1[2] = param_3;
  *param_1 = -1;
  lStack_a0 = param_1[1];
  lStack_98 = param_1[2];
  uStack_64 = 0;
  uStack_6c = 0;
  lStack_a8 = param_3;
  puVar12 = (undefined4 *)func_0x06c61450(param_4,auStack_90);
  (*(code *)&DAT_04732870)();
  puStack_80 = (undefined4 *)(*(code *)&DAT_04732830)(0x24,1);
  if (puStack_80 == (undefined4 *)0x0) goto code_r0x06e2c88b;
  puStack_80[8] = puVar12[8];
  uVar3 = *puVar12;
  uVar4 = puVar12[1];
  uVar5 = puVar12[2];
  uVar6 = puVar12[3];
  uVar7 = puVar12[5];
  uVar8 = puVar12[6];
  uVar9 = puVar12[7];
  puStack_80[4] = puVar12[4];
  puStack_80[5] = uVar7;
  puStack_80[6] = uVar8;
  puStack_80[7] = uVar9;
  *puStack_80 = uVar3;
  puStack_80[1] = uVar4;
  puStack_80[2] = uVar5;
  puStack_80[3] = uVar6;
  auStack_90[0] = 3;
  uStack_88 = 0x24;
  uStack_78 = 0x24;
  func_0x077d6570(abStack_60,param_1 + 3,&lStack_a8,auStack_90);
  if (abStack_60[0] < 3) {
    if (abStack_60[0] < 3) {
      return 0;
    }
code_r0x06e2c81d:
    func_0x07813660(&lStack_58);
  }
  else {
    if (abStack_60[0] == 3) {
      if (lStack_58 == 0) {
        return 0;
      }
      uVar13 = 1;
    }
    else {
      if (abStack_60[0] != 4) {
        if (abStack_60[0] == 0xff) {
          return 0;
        }
        goto code_r0x06e2c81d;
      }
      func_0x07c89080(&lStack_58);
      if (lStack_58 == 0) {
        return 0;
      }
      lStack_58 = lStack_58 << 5;
      uVar13 = 8;
    }
    (*(code *)&DAT_04732840)(uStack_50,lStack_58,uVar13);
  }
  return 0;
}

