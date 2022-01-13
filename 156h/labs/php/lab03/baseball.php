<?php

/**
 * Login: Ethan Riegsecker (ethanmr)
 * Date: 1/12/2022
 */

include_once("team.php");

/**
 * A comparator function to order Team instances based on win percentage,
 * most winning first.
 */
function teamComp($a, $b) {
  if($a->getWinPercentage() == $b->getWinPercentage()) {
    return 0;
  } else {
    return ($a->getWinPercentage() < $b->getWinPercentage() ? 1 : -1);
  }
}

function loadTeams() {
  $fileHandle = fopen("../data/mlb_nl_2011.csv", "r");
  $teams = array();
  $i = 0;
  while(!feof($fileHandle)) {
    $str = fgets($fileHandle);
    $tokens = explode(",", $str);
    if(count($tokens) == 3) {
      $team = new Team($tokens[0], intval($tokens[1]), intval($tokens[2]));
      $teams[$i] = $team;
    }
    $i++;
  }
  fclose($fileHandle); 
  return $teams;
}


  $teams = loadTeams();
  print "Teams: \n";
  foreach($teams as $team) {
    print $team . "\n";
  }

  usort($teams, "teamComp");

  print "\n\nSorted Teams: \n";
  foreach($teams as $team) {
    print $team . "\n";
  }

  $outStr = "";
  foreach($teams as $team) {
    $outStr .= $team->getName().",".$team->getWins().",".$team->getLosses()."\n";
  }
  file_put_contents("./out.txt", $outStr);

?>
