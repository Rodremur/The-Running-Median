#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}
 
#Test the program
eval spawn [lrange $argv 0 end]
 
#Put your test case here
send "6\r"
send "12\r"
expect "12.0\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "4\r"
expect "8.0\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "5\r"
expect "5.0\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "3\r"
expect "4.5\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "8\r"
expect "5.0\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}
send "7\r"
expect "6.0\r" {foreground green; puts "PASSED"; reset} default {foreground red; puts "FAILED"; reset}