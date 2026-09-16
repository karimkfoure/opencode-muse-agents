
undefined8 * fold_field_parse2(undefined8 *param_1,long param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 uStack_48;
  char cStack_40;
  undefined4 uStack_3f;
  undefined4 uStack_3b;
  undefined4 uStack_37;
  undefined3 uStack_33;
  undefined1 uStack_30;
  undefined3 uStack_2f;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_19;
  
  cVar1 = *(char *)(param_2 + 0x48);
  *(undefined1 *)(param_2 + 0x48) = 0xff;
  if (cVar1 == -1) {
    uVar3 = phase_step_emit(&UNK_00222500,0x10);
    param_1[1] = uVar3;
    *param_1 = 0xffffffffffffffff;
  }
  else {
    uStack_3f = *(undefined4 *)(param_2 + 0x49);
    uStack_3b = *(undefined4 *)(param_2 + 0x4d);
    uStack_37 = *(undefined4 *)(param_2 + 0x51);
    uStack_2c = *(undefined4 *)(param_2 + 0x5c);
    uStack_28 = *(undefined4 *)(param_2 + 0x60);
    uStack_24 = *(undefined4 *)(param_2 + 100);
    uStack_33 = (undefined3)*(undefined4 *)(param_2 + 0x55);
    uStack_30 = (undefined1)*(undefined4 *)(param_2 + 0x58);
    uStack_2f = (undefined3)((uint)*(undefined4 *)(param_2 + 0x58) >> 8);
    cStack_40 = cVar1;
    if (cVar1 == '\x05') {
      uStack_48 = *(undefined8 *)(param_2 + 0x60);
      uStack_58 = *(undefined4 *)(param_2 + 0x50);
      uStack_54 = *(undefined4 *)(param_2 + 0x54);
      uStack_50 = *(undefined4 *)(param_2 + 0x58);
      uStack_4c = *(undefined4 *)(param_2 + 0x5c);
      func_0x06d8b0e0(param_1,&uStack_58);
    }
    else if (cVar1 == '\x04') {
      func_0x0767e330(param_1,(long)&uStack_3b + 3);
    }
    else {
      uVar3 = func_0x072d97e0(&cStack_40,&uStack_19,&UNK_12146678);
      param_1[1] = uVar3;
      *param_1 = 0xffffffffffffffff;
      if ((cVar1 == '\x03') &&
         (lVar2 = CONCAT35(uStack_33,CONCAT41(uStack_37,uStack_3b._3_1_)), lVar2 != 0)) {
        (*(code *)&DAT_04732840)(CONCAT44(uStack_2c,CONCAT31(uStack_2f,uStack_30)),lVar2,1);
      }
    }
  }
  return param_1;
}

