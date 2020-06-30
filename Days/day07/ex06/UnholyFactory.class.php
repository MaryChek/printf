<?php
class UnholyFactory {
    private $fighter;
    public function absorb($pers) {
        if (is_subclass_of($pers, 'Fighter')) {
            if (!isset($this->fighter[$pers->type])) {
                $this->fighter[$pers->type] = $pers;
                print("(Factory absorbed a fighter of type ". $pers->type . ")" . PHP_EOL);
            }
            else
                print("(Factory already absorbed a fighter of type ". $pers->type . ")" . PHP_EOL);
        }
        else
            print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);

    }
    public function fabricate($fighter) {
        if (isset($this->fighter[$fighter])) {
            print("(Factory fabricates a fighter of type " . $fighter . ")" . PHP_EOL);
            return $this->fighter[$fighter];
        }
        else {
            print("(Factory hasn't absorbed any fighter of type " . $fighter . ")" . PHP_EOL);
            return null;
        }
    }
}
//(Factory absorbed a fighter of type foot soldier)
//(Factory already absorbed a fighter of type foot soldier)
//(Factory absorbed a fighter of type archer)
//(Factory absorbed a fighter of type assassin)
//(Factory can't absorb this, it's not a fighter)
//(Factory fabricates a fighter of type foot soldier)
//(Factory hasn't absorbed any fighter of type llama)
//(Factory fabricates a fighter of type foot soldier)
//(Factory fabricates a fighter of type archer)
//(Factory fabricates a fighter of type foot soldier)
//(Factory fabricates a fighter of type assassin)
//(Factory fabricates a fighter of type foot soldier)
//(Factory fabricates a fighter of type archer)

//* draws his sword and runs towards the Hound *
//* draws his sword and runs towards Tyrion *
//* draws his sword and runs towards Podrick *

//* draws his sword and runs towards the Hound *
//* draws his sword and runs towards Tyrion *
//* draws his sword and runs towards Podrick *

//* shoots arrows at the Hound *
//* shoots arrows at Tyrion *
//* shoots arrows at Podrick *

//* draws his sword and runs towards the Hound *
//* draws his sword and runs towards Tyrion *
//* draws his sword and runs towards Podrick *

//* creeps behind the Hound and stabs at it *
//* creeps behind Tyrion and stabs at it *
//* creeps behind Podrick and stabs at it *

//* draws his sword and runs towards the Hound *
//* draws his sword and runs towards Tyrion *
//* draws his sword and runs towards Podrick *

//* shoots arrows at the Hound *
//* shoots arrows at Tyrion *
//* shoots arrows at Podrick *