
void spawn_rec_writer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 uVar4;
  long lStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long lStack_70;
  long lStack_68;
  long lStack_60;
  long lStack_58;
  long lStack_50;
  long lStack_48;
  undefined8 uStack_40;
  undefined2 uStack_38;
  
  func_0x07b3e040(&lStack_70,param_2,param_3,0);
  lVar1 = lStack_68;
  lVar3 = lStack_70;
  if (lStack_70 == -1) {
    uVar4 = lStack_60 == 0;
    if (-1 < lStack_60) goto code_r0x0759ab2f;
    uVar2 = 0;
    do {
      uVar4 = 1;
      (*(code *)&DAT_1208422d)(uVar2,lStack_60);
code_r0x0759ab2f:
      if ((bool)uVar4) {
        lVar1 = 1;
        lVar3 = 0;
        lStack_60 = 0;
        goto code_r0x0759aa55;
      }
      (*(code *)&DAT_04732870)();
      uVar2 = 1;
      lVar1 = (*(code *)&DAT_04732830)(lStack_60,1);
    } while (lVar1 == 0);
    (*(code *)&DAT_120cba68)(lVar1,lStack_68,lStack_60);
    lVar3 = lStack_60;
  }
code_r0x0759aa55:
  lStack_48 = lVar1 + lStack_60;
  lStack_70 = 0;
  uStack_40 = 0;
  uStack_38 = 1;
  lStack_68 = lStack_60;
  lStack_58 = lStack_60;
  lStack_60 = lVar1;
  lStack_50 = lVar1;
  func_0x07bd3e20(&lStack_88,&lStack_70);
  func_0x069f8b50(&lStack_70,uStack_80,uStack_78,&UNK_006f6ad3,1);
  if (lStack_88 != 0) {
    (*(code *)&DAT_04732840)(uStack_80,lStack_88 << 4,8);
  }
  if (lVar3 != 0) {
    (*(code *)&DAT_04732840)(lVar1,lVar3,1);
  }
  lVar1 = lStack_68;
  func_0x0759ae00(param_1,lStack_68,lStack_60);
  if (lStack_70 != 0) {
    (*(code *)&DAT_04732840)(lVar1,lStack_70,1);
  }
  return;
}

