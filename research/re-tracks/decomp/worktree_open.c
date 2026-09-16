
undefined8 worktree_open(long *param_1,char param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 auStack_80 [8];
  undefined8 uStack_78;
  undefined8 *puStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  long lStack_58;
  long lStack_50;
  byte abStack_48 [8];
  long lStack_40;
  undefined8 uStack_38;
  
  lVar1 = *param_1;
  if (lVar1 == -2) {
    uVar3 = (*(code *)&DAT_0ff4ab00)();
    return uVar3;
  }
  (*(code *)&DAT_04732870)();
  puVar4 = (undefined8 *)(*(code *)&DAT_04732830)(0xe,1);
  if (puVar4 == (undefined8 *)0x0) {
code_r0x06e1b4b5:
    (*(code *)&DAT_1208422d)(1,0xe);
code_r0x06e1b4c5:
    (*(code *)&DAT_1208422d)(1,0x11);
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
  *(undefined8 *)((long)puVar4 + 6) = 0x736369746e616d65;
  *puVar4 = 0x6d65735f68746170;
  if ((lVar1 != -1) && (lVar1 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar1,1);
  }
  param_1[1] = (long)puVar4;
  param_1[2] = 0xe;
  *param_1 = -1;
  lStack_58 = param_1[1];
  lStack_50 = param_1[2];
  uStack_60 = 0xe;
  (*(code *)&DAT_04732870)();
  if (param_2 == '\x01') {
    uVar3 = 0x11;
    puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(0x11,1);
    if (puStack_70 == (undefined8 *)0x0) goto code_r0x06e1b4c5;
    *(undefined1 *)(puStack_70 + 2) = 0x65;
    *(undefined4 *)puStack_70 = 0x635f3376;
    *(undefined4 *)((long)puStack_70 + 4) = 0x6e6f6e61;
    *(undefined4 *)(puStack_70 + 1) = 0x6c616369;
    *(undefined4 *)((long)puStack_70 + 0xc) = 0x6d616e5f;
  }
  else {
    uVar3 = 0xe;
    puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(0xe,1);
    if (puStack_70 == (undefined8 *)0x0) goto code_r0x06e1b4b5;
    *(undefined8 *)((long)puStack_70 + 6) = 0x6c616e6964726f5f;
    *puStack_70 = 0x6f5f79636167656c;
  }
  auStack_80[0] = 3;
  uStack_78 = uVar3;
  uStack_68 = uVar3;
  bind_validator(abStack_48,param_1 + 3,&uStack_60,auStack_80);
  if (abStack_48[0] < 3) {
    if (abStack_48[0] < 3) {
      return 0;
    }
code_r0x06e1b462:
    record_release(&lStack_40);
  }
  else {
    if (abStack_48[0] == 3) {
      if (lStack_40 == 0) {
        return 0;
      }
      uVar3 = 1;
    }
    else {
      if (abStack_48[0] != 4) {
        if (abStack_48[0] == 0xff) {
          return 0;
        }
        goto code_r0x06e1b462;
      }
      func_0x07c89080(&lStack_40);
      if (lStack_40 == 0) {
        return 0;
      }
      lStack_40 = lStack_40 << 5;
      uVar3 = 8;
    }
    (*(code *)&DAT_04732840)(uStack_38,lStack_40,uVar3);
  }
  return 0;
}

