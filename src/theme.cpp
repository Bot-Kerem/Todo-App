#include "theme.h"

Theme getDefaultTheme(){
    Theme theme;
    theme.Background = Color(0.52f);
    theme.PillCircle = Color(0.0f, 1.0f, 0.0f);
    theme.PillSquare = Color(0.0f, 1.0f, 1.0f);
    return theme;
}