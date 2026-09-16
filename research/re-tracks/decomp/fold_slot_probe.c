
void fold_slot_probe(long *param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  uint uVar5;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined1 uStack_21;
  
  if ((char)*param_2 == '\0') {
    *param_1 = -1;
    return;
  }
  uStack_48 = *param_2;
  uStack_44 = param_2[1];
  uStack_40 = param_2[2];
  uStack_3c = param_2[3];
  lVar1 = *(long *)(param_2 + 2);
  uStack_38 = param_2[4];
  uStack_34 = param_2[5];
  lVar4 = *(long *)(param_2 + 4);
  uStack_30 = param_2[6];
  uStack_2c = param_2[7];
  lVar2 = *(long *)(param_2 + 6);
  cVar3 = (char)uStack_48;
  uVar5 = uStack_48 & 0xff;
  if (uVar5 == 3) {
    if (lVar1 != -1) {
      *param_1 = lVar1;
      param_1[1] = lVar4;
      param_1[2] = lVar2;
      return;
    }
  }
  else {
    lVar4 = func_0x072d97e0(&uStack_48,&uStack_21,&UNK_121464f8);
    if (2 < uVar5) {
      if (cVar3 == '\x04') {
        func_0x07c89080();
        if (CONCAT44(uStack_3c,uStack_40) != 0) {
          (*(code *)&DAT_04732840)
                    (CONCAT44(uStack_34,uStack_38),CONCAT44(uStack_3c,uStack_40) << 5,8);
        }
      }
      else {
        record_release(&uStack_40);
      }
    }
  }
  param_1[1] = lVar4;
  *param_1 = -2;
  return;
}

