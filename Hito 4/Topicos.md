# Como discretizamos el controlador
con el bloque parameters discrete*time
# cual es la formula que hay que utilizar compemsator formula
P+I*T*(1/(z-1))
# PI
PI = 1 + 1/0.5s continious time transfer funcion
# PI_D 
PI_D = c2s(PI,0.1) Sample time 0.1s

