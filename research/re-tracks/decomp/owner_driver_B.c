
undefined8 *
owner_driver_B(undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,long *param_5)

{
  undefined4 *puVar1;
  char cVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lStack_170;
  long lStack_168;
  long lStack_160;
  long lStack_b0;
  long lStack_a8;
  long *plStack_a0;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  long lStack_50;
  long *plStack_48;
  long lStack_40;
  undefined1 uStack_31;
  
  if (((char)param_4[3] == '\0') && (param_4[2] == 0)) {
    owner_child_control(&uStack_60,param_3);
    lVar8 = lStack_50;
    lVar4 = CONCAT44(uStack_5c,uStack_60);
    lStack_40 = CONCAT44(uStack_54,uStack_58);
    if (*param_4 != 0) {
      (*(code *)&DAT_04732840)(param_4[1],*param_4 * 0x18,8);
    }
    *param_4 = lVar4;
    param_4[1] = lStack_40;
    param_4[2] = lVar8;
    *(undefined1 *)(param_4 + 3) = 0;
    plStack_48 = param_5;
    if (lVar8 == 0) {
      lVar4 = 8;
    }
    else {
      lVar6 = lVar8 * 0x18;
      (*(code *)&DAT_04732870)();
      lVar4 = (*(code *)&DAT_04732830)(lVar6,8);
      if (lVar4 == 0) {
        puVar3 = (undefined8 *)0x8;
        (*(code *)&DAT_1208422d)(8,lVar6);
        lStack_a8 = lVar8;
        plStack_a0 = param_5;
        (*(code *)&DAT_0722aa60)(&lStack_170);
        lVar4 = lStack_170;
        if (lStack_170 == -2) {
          puVar3[1] = lStack_168;
          *puVar3 = 0xfffffffffffffffd;
        }
        else {
          if (lStack_170 == -1) {
            lStack_170 = -2;
          }
          else {
            lStack_b0 = lStack_168;
            (*(code *)&DAT_0e09bdc0)(&lStack_170,lStack_168,lStack_160);
            if (lStack_160 != 0) {
              lVar8 = lStack_b0 + 0x28;
              lVar6 = lStack_160;
              do {
                if (*(long *)(lVar8 + -0x28) != 0) {
                  (*(code *)&DAT_04732840)
                            (*(undefined8 *)(lVar8 + -0x20),*(long *)(lVar8 + -0x28),1);
                }
                func_0x07aec270(lVar8);
                lVar8 = lVar8 + 0xa8;
                lVar6 = lVar6 + -1;
              } while (lVar6 != 0);
            }
            if (lVar4 != 0) {
              (*(code *)&DAT_04732840)(lStack_b0,lVar4 * 0xa8,8);
            }
          }
          (*(code *)&DAT_120cba68)(puVar3,&lStack_170,0xc0);
        }
        return puVar3;
      }
      lVar7 = 0;
      lVar5 = lVar8;
      do {
        if (lVar6 == lVar7) break;
        (*(code *)&DAT_120846f0)(&uStack_60,lStack_40 + lVar7);
        *(long *)(lVar4 + 0x10 + lVar7) = lStack_50;
        puVar1 = (undefined4 *)(lVar4 + lVar7);
        *puVar1 = uStack_60;
        puVar1[1] = uStack_5c;
        puVar1[2] = uStack_58;
        puVar1[3] = uStack_54;
        lVar7 = lVar7 + 0x18;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
    }
    lStack_40 = plStack_48[1];
    lVar6 = plStack_48[2];
    if (lVar6 != 0) {
      puVar3 = (undefined8 *)(lStack_40 + 8);
      do {
        if (puVar3[-1] != 0) {
          (*(code *)&DAT_04732840)(*puVar3,puVar3[-1],1);
        }
        puVar3 = puVar3 + 3;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
    }
    param_5 = plStack_48;
    if (*plStack_48 != 0) {
      (*(code *)&DAT_04732840)(lStack_40,*plStack_48 * 0x18,8);
    }
    *param_5 = lVar8;
    param_5[1] = lVar4;
    param_5[2] = lVar8;
    puVar3 = (undefined8 *)(*(code *)&DAT_0af79e80)(param_1,param_2);
    cVar2 = (char)puVar3;
  }
  else {
    puVar3 = (undefined8 *)(*(code *)&DAT_0af79e80)();
    cVar2 = (char)puVar3;
  }
  if (cVar2 == '\0') {
    func_0x07abab10(param_4,&uStack_31);
    puVar3 = (undefined8 *)func_0x07abab10(param_5,&uStack_31);
  }
  return puVar3;
}

