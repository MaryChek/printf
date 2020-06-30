<?php
class Color
{
    public $verbose = false;
    public $red;
    public $green;
    public $blue;
    public function __construct(array $colors)
    {
        if (isset($colors['rgb'])) {
            $color = intval($colors['rgb'], 10);
            $this->blue = $color % 256;
            $color = intdiv($color, 256);
            $this->green = $color % 256;
            $color = intdiv($color, 256);
            $this->red = $color % 256;
        } else if (isset($colors['red']) && isset($colors['green']) && isset($colors['blue'])) {
            $this->red = $colors['red'];
            $this->blue = $colors['blue'];
            $this->green = $colors['green'];
        }
        if ($this->verbose = true) {
            print $this."constructed.";
        }
    }
    public function __toString()
    {
        return "Color (red: ".$this->red.", green: ".$this->green.", blue: ".$this->blue." )";
    }

}