__Macroses



;################ Register's Flags Manipulate ##################
    MACRO 
$label FLAG $m, $reg, $flag
    LDR tmpa, =$reg
    LDR tmpd, [tmpa]
    LDR tmp, =$flag
    IF ("$m" = "clear")
        BICS tmpd, tmp
    ELIF ("$m" = "set")
        ORRS tmpd, tmp
    ELSE
        INFO 1, "Use \"set\" or \"clear\" flag parameter."
    ENDIF
    STR tmpd, [tmpa]
    MEND

    MACRO 
$label REG $m, $reg, $flag
    FLAG $m, $reg, $flag
    MEND



;#################### Check Register's Flag ####################
    MACRO 
$label FLAG_CHK $m, $reg, $flag, $path
    LDR tmpa, =$reg
    LDR tmpd, [tmpa]
    LSRS tmpd, #$flag + 1
    IF ("$m" = "clear")
        BCC $path
    ELIF ("$m" = "set")
        BCS $path
    ELSE
        INFO 1, "Use \"set\" or \"clear\" flag parameter."
    ENDIF
    MEND




;########################### PSR ##############################
    MACRO
$label APSRC $flag
    LDR tmp, =$flag
    MRS tmpd, APSR
    BICS tmpd, tmp
    MSR APSR_nzcvq, tmpd
    MEND


    END
