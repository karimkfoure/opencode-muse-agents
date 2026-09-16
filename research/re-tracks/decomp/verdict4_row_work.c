
void verdict4_row_work(long *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  
  if (*param_1 != 0) {
    (*(code *)&DAT_04732840)(param_1[1],*param_1,1);
  }
  if (param_1[3] != 0) {
    (*(code *)&DAT_04732840)(param_1[4],param_1[3],1);
  }
  if (param_1[6] != 0) {
    (*(code *)&DAT_04732840)(param_1[7],param_1[6],1);
  }
  if (param_1[9] != 0) {
    (*(code *)&DAT_04732840)(param_1[10],param_1[9],1);
  }
  if (param_1[0xc] != 0) {
    (*(code *)&DAT_04732840)(param_1[0xd],param_1[0xc],1);
  }
  lVar1 = param_1[0x10];
  lVar3 = param_1[0x11];
  if (lVar3 != 0) {
    puVar2 = (undefined8 *)(lVar1 + 0x38);
    do {
      if (puVar2[-7] != 0) {
        (*(code *)&DAT_04732840)(puVar2[-6],puVar2[-7],1);
      }
      if (puVar2[-4] != 0) {
        (*(code *)&DAT_04732840)(puVar2[-3],puVar2[-4],1);
      }
      if (puVar2[-1] != 0) {
        (*(code *)&DAT_04732840)(*puVar2,puVar2[-1],1);
      }
      puVar2 = puVar2 + 0xc;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  if (param_1[0xf] != 0) {
    (*(code *)&DAT_04732840)(lVar1,param_1[0xf] * 0x60,8);
  }
  if (param_1[0x12] != 0) {
    (*(code *)&DAT_04732840)(param_1[0x13],param_1[0x12],1);
  }
  if (param_1[0x15] != 0) {
    (*(code *)&DAT_04732840)(param_1[0x16],param_1[0x15],1);
    return;
  }
  return;
}

