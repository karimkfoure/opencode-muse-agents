
void intake_dispatcher(undefined8 param_1,ulong *param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (1 < *param_2) {
    lVar1 = *param_2 - 2;
  }
                    /* WARNING: Could not recover jumptable at 0x05a1fbb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&UNK_0066be1c + *(int *)(&UNK_0066be1c + lVar1 * 4)))();
  return;
}

