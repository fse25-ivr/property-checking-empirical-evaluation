				// spec.1        
				assert(!(dw.is_ON == IN_NO_ACTIVE_CHILD && (((dw.was_ON == IN_AMMode) && (dw.was_ModeManager == IN_Standby) && (rtU.RadioReq == AM) && !rtU.DiscEject && (dw.is_c1_model == IN_ModeManager)) || ((dw.was_ON == IN_AMMode) && !(dw.was_ModeManager == IN_Standby)) || (!(dw.was_ON == IN_AMMode) && (rtU.RadioReq == AM) && (dw.is_c1_model == IN_ModeManager) && !rtU.DiscEject))) || rtDW.is_ON == IN_AMMode);
				// spec.2
				assert(!(dw.is_ON == IN_NO_ACTIVE_CHILD && (((dw.was_ON == IN_FMMode) && (dw.was_ModeManager == IN_Standby) && (rtU.RadioReq == FM) && !rtU.DiscEject && (dw.is_c1_model == IN_ModeManager)) || ((dw.was_ON == IN_FMMode) && !(dw.was_ModeManager == IN_Standby)) || (!(dw.was_ON == IN_FMMode) && (rtU.RadioReq == FM) && !(dw.is_ModeManager == IN_NO_ACTIVE_CHILD) && !rtU.DiscEject))) || rtDW.is_ON == IN_FMMode);
				// spec.3
				assert(!(dw.is_ON == IN_NO_ACTIVE_CHILD && (((dw.was_ON == IN_CDMode) && (dw.was_ModeManager == IN_ON)) || ((dw.was_ON == IN_CDMode) && !(dw.was_ModeManager == IN_ON) && (rtU.RadioReq == CD) && !rtU.DiscEject && !(dw.is_c1_model == IN_Eject)) || (!(dw.was_ON == IN_CDMode) && (rtU.RadioReq == CD) && !(dw.is_ModeManager == IN_NO_ACTIVE_CHILD) && !rtU.DiscEject))) || rtDW.is_ON == IN_CDMode);
				// spec.4
				assert(!(dw.is_ON == IN_AMMode && ((rtU.RadioReq == FM) && !rtU.DiscEject && !(dw.RadioReq_start == FM))) || rtDW.is_ON == IN_FMMode);
				// spec.5
				assert(!(dw.is_ON == IN_AMMode && ((rtU.RadioReq == CD) && !rtU.DiscEject && !(dw.RadioReq_start == CD))) || rtDW.is_ON == IN_CDMode);
				// spec.6
				assert(!(dw.is_ON == IN_AMMode && (rtU.DiscEject || (!rtU.DiscEject && !(rtU.RadioReq == CD) && !(rtU.RadioReq == AM) && !(rtU.RadioReq == FM)))) || rtDW.is_ON == IN_NO_ACTIVE_CHILD);
				// spec.7
				assert(!(dw.is_ON == IN_FMMode && (rtU.DiscEject || (!rtU.DiscEject && !(rtU.RadioReq == AM) && !(rtU.RadioReq == FM) && !(rtU.RadioReq == CD)))) || rtDW.is_ON == IN_NO_ACTIVE_CHILD);
				// spec.8
				assert(!(dw.is_ON == IN_FMMode && ((rtU.RadioReq == CD) && !rtU.DiscEject && !(dw.RadioReq_start == CD))) || rtDW.is_ON == IN_CDMode);
				// spec.9
				assert(!(dw.is_ON == IN_FMMode && ((rtU.RadioReq == AM) && !rtU.DiscEject && !(dw.RadioReq_start == AM))) || rtDW.is_ON == IN_AMMode);
				// spec.10
				assert(!(dw.is_ON == IN_CDMode && ((rtU.RadioReq == FM) && !rtU.DiscEject && !(dw.RadioReq_start == FM))) || rtDW.is_ON == IN_FMMode);
				// spec.11
				assert(!(dw.is_ON == IN_CDMode && ((rtU.RadioReq == AM) && !rtU.DiscEject && !(dw.RadioReq_start == AM))) || rtDW.is_ON == IN_AMMode);
				// spec.12
				assert(!(dw.is_ON == IN_CDMode && (rtU.DiscEject || (!rtU.DiscEject && !(rtU.RadioReq == CD) && !(rtU.RadioReq == FM) && !(rtU.RadioReq == AM)))) || rtDW.is_ON == IN_NO_ACTIVE_CHILD);