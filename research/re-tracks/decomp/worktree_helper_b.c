
undefined8 worktree_helper_b(long *param_1,long param_2,long param_3,uint *param_4)

{
  long lVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  undefined1 auStack_98 [8];
  undefined8 uStack_90;
  ulong uStack_88;
  long lStack_78;
  long lStack_70;
  long lStack_68;
  byte abStack_60 [8];
  long lStack_58;
  undefined8 uStack_50;
  uint *puStack_40;
  long lStack_38;
  
  lVar1 = *param_1;
  if (lVar1 == -2) {
    (*(code *)&DAT_1208f3b0)(&UNK_006d32dc,0x28,&UNK_12138800);
    pcVar2 = (code *)swi(3);
    uVar5 = (*pcVar2)();
    return uVar5;
  }
  uVar6 = param_3 == 0;
  if (-1 < param_3) goto code_r0x06e2f845;
  plVar3 = (long *)0x0;
  do {
    param_1 = plVar3;
    uVar6 = 1;
    param_2 = param_3;
    (*(code *)&DAT_1208422d)();
code_r0x06e2f845:
    if ((bool)uVar6) {
      lVar4 = 1;
      goto joined_r0x06e2f89d;
    }
    puStack_40 = param_4;
    lStack_38 = param_2;
    (*(code *)&DAT_04732870)();
    lVar4 = (*(code *)&DAT_04732830)(param_3,1);
    plVar3 = (long *)0x1;
  } while (lVar4 == 0);
  (*(code *)&DAT_120cba68)(lVar4,lStack_38,param_3);
  param_4 = puStack_40;
joined_r0x06e2f89d:
  if ((lVar1 != -1) && (lVar1 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar1,1);
  }
  param_1[1] = lVar4;
  param_1[2] = param_3;
  uStack_88 = (ulong)*param_4;
  *param_1 = -1;
  lStack_70 = param_1[1];
  lStack_68 = param_1[2];
  auStack_98[0] = 2;
  uStack_90 = 0;
  lStack_78 = param_3;
  bind_validator(abStack_60,param_1 + 3,&lStack_78,auStack_98);
  if (abStack_60[0] < 3) {
    if (abStack_60[0] < 3) {
      return 0;
    }
code_r0x06e2f92b:
    func_0x07813660(&lStack_58);
  }
  else {
    if (abStack_60[0] == 3) {
      if (lStack_58 == 0) {
        return 0;
      }
      uVar5 = 1;
    }
    else {
      if (abStack_60[0] != 4) {
        if (abStack_60[0] == 0xff) {
          return 0;
        }
        goto code_r0x06e2f92b;
      }
      func_0x07c89080(&lStack_58);
      if (lStack_58 == 0) {
        return 0;
      }
      lStack_58 = lStack_58 << 5;
      uVar5 = 8;
    }
    (*(code *)&DAT_04732840)(uStack_50,lStack_58,uVar5);
  }
  return 0;
}

