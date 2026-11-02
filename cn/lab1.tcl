set ns [new Simulator]

set nf [open lab1.nam w]
set tf [open lab1.tr w]

$ns namtrace-all $nf
$ns trace-all $tf

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 0.001Mb 10ms DropTail

$ns queue-limit $n0 $n1 5
$ns queue-limit $n1 $n2 1

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

set null0 [new Agent/Null]
$ns attach-agent $n2 $null0

$ns connect $udp0 $null0

set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005

proc finish {} {
    global ns nf tf

    $ns flush-trace

    close $nf
    close $tf

    set drops [exec awk {BEGIN{d=0} $1=="d"{d++} END{print d}} lab1.tr]

    puts "Number of packets dropped: $drops"

    exec nam lab1.nam &
    exit 0
}

$ns at 0.1 "$cbr0 start"
$ns at 9.9 "$cbr0 stop"
$ns at 10.0 "finish"

$ns run