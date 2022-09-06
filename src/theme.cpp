#include "theme.h"

Theme getDefaultTheme(){
    Theme theme;
    theme.Background = Color(0.52f);
    theme.PillCircle = Color(0.0f, 0.7f, 0.7f);
    theme.PillSquare = Color(0.3f, 0.3f, 0.1f);
    theme.EditModeHover = Color(0.6f, 0.6f, 1.0f);
    theme.Main = Color(1.0f);
    return theme;
}