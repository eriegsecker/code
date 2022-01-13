<?php

/**
 * 
 * Login: Ethan Riegsecker (ethanmr)
 * 
 * Date: 1/12/2022
 *
 */

/**
 * Loads DNA from the specified file line by line, stripping all
 * whitespace and returning the DNA string.
 */
function loadDnaFromFile() {

  $fileContents = "";
  $fileHandle = fopen("../data/H1N1nucleotide.txt", "r");

  while(!feof($fileHandle)) {
    //get the next line
    $line = fgets($fileHandle);
    //concatenate
    $fileContents .= $line;
  }
  fclose($fileHandle);

  //strip all whitespace
  $dna = preg_replace("/\s*/", "", $fileContents); 
  return $dna; 
}

/**
  * Counts the number of times $subSequence appears in the
  * given $dna string.
  */
function countSubsequences($dna, $subSequence) {
  $count = substr_count($dna, $subSequence);
  return $count;
}

if(count($argv) < 2) {
  print "Not enough arguments\n";
  exit(1);
}
$subSequence = $argv[1];
$dna = loadDnaFromFile();
$count = countSubsequences($dna, $subSequence); 
printf("%s appears %d times\n", $subSequence, $count);

?>
