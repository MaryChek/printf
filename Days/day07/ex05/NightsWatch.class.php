<?php
class NightsWatch implements IFighter {
    public function recruit($name) {
        if (is_subclass_of($name, 'IFighter')) {
            $name->fight();
        }
    }
    public function fight(){}
}