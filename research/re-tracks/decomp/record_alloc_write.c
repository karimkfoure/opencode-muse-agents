
long * record_alloc_write(long *param_1,long *param_2,long param_3,undefined8 param_4,
                         undefined8 param_5,long *param_6,ulong param_7,char param_8)

{
  long lVar1;
  long extraout_RDX;
  long lVar2;
  long *unaff_R12;
  long unaff_R14;
  long lVar3;
  long lStack_48;
  long lStack_40;
  long lStack_38;
  
  if (param_2 == (long *)0x0) {
code_r0x0757c98e:
    *param_1 = -1;
    return param_1;
  }
  if (param_3 != 0xf) {
    if ((param_3 != 0xb) ||
       (((*(long *)((long)param_2 + 3) != 0x6863726165735f6c || *param_2 != 0x6165735f6c6f6f74 &&
         (*(long *)((long)param_2 + 3) != 0x6c616f675f657461 || *param_2 != 0x675f657461657263)) ||
        (func_0x07577290(&lStack_48,param_2,0xb), lStack_48 == -1)))) goto code_r0x0757c98e;
    goto code_r0x0757c91b;
  }
  if (((param_7 < 8 || param_8 != '\x01') ||
       (*(long *)((long)param_2 + 7) != 0x7265646e696d6572 || *param_2 != 0x725f657a6f6f6e73)) ||
     (*param_6 != 0x2064657a6f6f6e73)) goto code_r0x0757c98e;
  lVar2 = param_7 - 8;
  if (lVar2 < 0) {
    lVar3 = 0;
    param_1 = unaff_R12;
code_r0x0757c9b0:
    (*(code *)&DAT_1208422d)(lVar3,lVar2);
  }
  else {
    if (lVar2 == 0) {
      lStack_40 = 1;
      lStack_48 = lVar2;
      lStack_38 = lVar2;
    }
    else {
      (*(code *)&DAT_04732870)();
      lVar3 = 1;
      lVar1 = (*(code *)&DAT_04732830)(lVar2,1);
      if (lVar1 == 0) goto code_r0x0757c9b0;
      (*(code *)&DAT_120cba68)(lVar1,param_6 + 1,lVar2);
      lStack_48 = lVar2;
      lStack_40 = lVar1;
      lStack_38 = lVar2;
    }
code_r0x0757c91b:
    unaff_R14 = lStack_40;
    lVar3 = lStack_48;
    func_0x072b2330(lStack_40,lStack_38);
    if (extraout_RDX != 0) {
      param_1[2] = lStack_38;
      *param_1 = lStack_48;
      param_1[1] = lStack_40;
      return param_1;
    }
  }
  if (lVar3 != 0) {
    (*(code *)&DAT_04732840)(unaff_R14,lVar3,1);
  }
  *param_1 = -1;
  return param_1;
}

