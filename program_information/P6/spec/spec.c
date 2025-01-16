
				// spec.1
				assert(!((dw.is_On == IN_NO_ACTIVE_CHILD) && (rtDW.is_On == IN_Pending)));
				// spec.2
				assert(!(dw.is_On == IN_Idle_j && ((event_store == event_Alert) && !(rtU.Alarm_active == 0))) || rtDW.is_On == IN_Pending);
				// spec.3
				assert(!(dw.is_On == IN_Idle_j && (rtU.Alarm_active == 0)) || rtDW.is_On == IN_NO_ACTIVE_CHILD);
				// spec.4
				assert(!(dw.is_On == IN_Pending && (rtU.Alarm_active == 0)) || rtDW.is_On == IN_NO_ACTIVE_CHILD);
				// spec.5
				assert(!(dw.is_On == IN_Pending && ((79 == dw.temporalCounter_i2) && !(rtU.Alarm_active == 0))) || rtDW.is_On == IN_Idle_j);
				// spec.6
				assert(!(dw.is_On == IN_NO_ACTIVE_CHILD && (((rtU.Alarm_active == 0) && (dw.is_Alarm == IN_NO_ACTIVE_CHILD)) || !(rtU.Alarm_active == 0))) || rtDW.is_On == IN_Idle_j);
