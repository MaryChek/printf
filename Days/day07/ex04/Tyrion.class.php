<?php
class Tyrion extends Lannister {
    public function sleepWith($name)
    {
        if (get_class($name) == 'Jaime')
            echo "Not even if I'm drunk !" . PHP_EOL;
        if (get_class($name) == 'Sansa') {
            echo "Let's do this." . PHP_EOL;
        }
        if (get_class($name) == 'Cersei') {
            echo "Not even if I'm drunk !" . PHP_EOL;
        }
    }
}