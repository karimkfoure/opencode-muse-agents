
undefined8 worktree_x1(long *param_1,char param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
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
  puVar4 = (undefined4 *)(*(code *)&DAT_04732830)(0x15,1);
  if (puVar4 == (undefined4 *)0x0) {
    (*(code *)&DAT_1208422d)(1,0x15);
code_r0x06e16edb:
    (*(code *)&DAT_1208422d)(1,8);
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
  *puVar4 = 0x696d6461;
  puVar4[1] = 0x6f697373;
  puVar4[2] = 0x69645f6e;
  puVar4[3] = 0x736f7073;
  *(undefined8 *)((long)puVar4 + 0xd) = 0x6e6f697469736f70;
  if ((lVar1 != -1) && (lVar1 != 0)) {
    (*(code *)&DAT_04732840)(param_1[1],lVar1,1);
  }
  param_1[1] = (long)puVar4;
  param_1[2] = 0x15;
  *param_1 = -1;
  lStack_58 = param_1[1];
  lStack_50 = param_1[2];
  uStack_60 = 0x15;
  (*(code *)&DAT_04732870)();
  puStack_70 = (undefined8 *)(*(code *)&DAT_04732830)(8,1);
  if (param_2 == '\x01') {
    if (puStack_70 == (undefined8 *)0x0) goto code_r0x06e16edb;
    uVar3 = 0x64657463656a6572;
  }
  else {
    if (puStack_70 == (undefined8 *)0x0) goto code_r0x06e16edb;
    uVar3 = 0x6465747065636361;
  }
  *puStack_70 = uVar3;
  auStack_80[0] = 3;
  uStack_78 = 8;
  uStack_68 = 8;
  bind_validator(abStack_48,param_1 + 3,&uStack_60,auStack_80);
  if (abStack_48[0] < 3) {
    if (abStack_48[0] < 3) {
      return 0;
    }
code_r0x06e16e78:
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
        goto code_r0x06e16e78;
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

