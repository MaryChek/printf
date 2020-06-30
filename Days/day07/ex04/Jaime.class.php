<?php
class Jaime extends Lannister {
    public function sleepWith($name)
    {
        if (get_class($name) == 'Tyrion')
            echo "Not even if I'm drunk !" . PHP_EOL;
        if (get_class($name) == 'Sansa') {
            echo "Let's do this." . PHP_EOL;
        }
        if (get_class($name) == 'Cersei') {
            echo "With pleasure, but only in a tower in Winterfell, then." . PHP_EOL;
        }
    }
}