set ns [new Simulator]

set nf [open lab2.nam w]
set tf [open lab2.tr w]

$ns namtrace-all $nf
$ns trace-all $tf

for {set i 0} {$i < 6} {incr i} {
    set n($i) [$ns node]
}

$ns duplex-link $n(0) $n(4) 1Mb 1ms DropTail
$ns duplex-link $n(1) $n(4) 5Mb 1ms DropTail
$ns duplex-link $n(2) $n(4) 2Mb 1ms DropTail
$ns duplex-link $n(3) $n(4) 2Mb 1ms DropTail
$ns duplex-link $n(4) $n(5) 1Mb 1ms DropTail

$ns queue-limit $n(0) $n(4) 20

$ns duplex-link-op $n(0) $n(4) orient right
$ns duplex-link-op $n(1) $n(4) orient right-down
$ns duplex-link-op $n(2) $n(4) orient down
$ns duplex-link-op $n(3) $n(4) orient left-down
$ns duplex-link-op $n(4) $n(5) orient right

for {set i 0} {$i < 6} {incr i} {
    set p($i) [new Agent/Ping]
    $ns attach-agent $n($i) $p($i)
}

Agent/Ping instproc recv {from rtt} {
    $self instvar node_
    puts "Node [$node_ id] received reply from $from. RTT = $rtt ms"
}

$ns connect $p(0) $p(5)
$ns connect $p(1) $p(5)
$ns connect $p(2) $p(3)

proc finish {} {
    global ns nf tf

    $ns flush-trace

    close $nf
    close $tf

    set drops [exec awk {BEGIN{d=0} $1=="d"{d++} END{print d}} lab2.tr]

    puts "Number of packets dropped: $drops"

    exec nam lab2.nam &
    exit 0
}

$ns at 0.1 "$p(0) send"
$ns at 0.2 "$p(0) send"
$ns at 0.3 "$p(0) send"
$ns at 0.4 "$p(0) send"
$ns at 0.5 "$p(0) send"

$ns at 0.1 "$p(1) send"
$ns at 0.2 "$p(1) send"

$ns at 0.1 "$p(2) send"
$ns at 0.2 "$p(2) send"
$ns at 0.3 "$p(2) send"

$ns at 0.7 "finish"

$ns run
