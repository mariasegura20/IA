(defglobal ?*YEAR* = 2023)
(defglobal ?*LIMITE1* = 900)

(deffunction Dec (?num)
    (- ?num 1)
)

(deffunction Dif (?v1 ?v2)
    (- ?v1 ?v2)    
)

(deftemplate Usuario
    (field DNI)
    (field Pin)
    (field Dinero (default 0))
)

(deftemplate Tarjeta
    (field DNI)
    (field Pin)
    (field intentos (default 3))
    (field limite (default 300))
    (field year (default 2027))
    (field validada (allowed-values Si No) (default No))
)

(deftemplate Cuenta
    (field DNI)
    (field Saldo)
    (field estado (allowed-values enPantalla dineroEntregado inicial SuperaLimite SinSaldo) (default inicial))
)

(deffacts iniciales
    (Tarjeta (DNI 123456) (Pin 1212) (intentos 3) (limite 500) (year 2026))
    (Tarjeta (DNI 456456) (Pin 1211) (intentos 3) (limite 500) (year 2026))
    (Tarjeta (DNI 000111) (Pin 0011) (intentos 0) (limite 500) (year 2026))

    (Cuenta (DNI 123456) (Saldo 5000))
    (Cuenta (DNI 456456) (Saldo 33))
    (Cuenta (DNI 000111) (Saldo 30000))
)

(defrule Supera_Intentos
    (declare (salience 2))
    (Usuario (DNI ?dni))
    (Tarjeta (DNI ?dni) (intentos 0))
    => (println "Se ha superado el numero de intentos")
)

(defrule Pin_Invalido
    (declare (salience 1))
    ?u <- (Usuario (DNI ?dni) (Pin ?pin1))
    ?t <- (Tarjeta (DNI ?dni) (Pin ?pin2) (intentos ?intentos))
    (test (neq ?pin1 ?pin2))
    (test (> ?intentos 0))
    => 
    (modify ?t (intentos (Dec ?intentos)))
    (retract ?u)
    (println "Pin invalido")
)

(defrule Valida_Tarjeta
    ?u <- (Usuario (DNI ?dni) (Pin ?pin1))
    ?t <- (Tarjeta (DNI ?dni) (Pin ?pin1) (intentos ?intentos) (year ?year) (validada No))
    (test (> ?intentos 0))
    (test (>= ?year ?*YEAR*))
    => 
    (modify ?t (validada Si))
    (println "Tarjeta validada")
)

(defrule Muestra_Saldo
    (Tarjeta (DNI ?dni) (validada Si))
    (Cuenta (DNI ?dni) (estado enPantalla) (Saldo ?saldo))
    =>
    (println "Saldo actual: " ?saldo)
)

(defrule Saldo_NoSuficiente
    (Usuario (DNI ?dni) (Dinero ?dinero))
    (Cuenta (DNI ?dni) (Saldo ?saldo))
    (test (> ?dinero ?saldo))
    =>
    (println "Saldo insuficiente")
)

(defrule Comprueba_Limite1
    (Usuario (Dinero ?dinero))
    (test (< ?*LIMITE1* ?dinero))
    =>
    (println "Supera el limite del banco")
)

(defrule Comprueba_Limite2
    (Usuario (DNI ?dni) (Dinero ?dinero))
    (Tarjeta (DNI ?dni) (limite ?limite))
    (test (< ?limite ?dinero))
    =>
    (println "Supera el limite de la tarjeta")
)

(defrule Entrega_Dinero
    (declare (salience -1))
    ?x <- (Usuario (DNI ?dni) (Dinero ?dinero))
    ?y <- (Cuenta (DNI ?dni) (Saldo ?saldo))
    =>
    (modify ?y (Saldo (Dif ?saldo ?dinero)))
    (retract ?x)
)

(defrule inicial
    (declare(salience 3))
    =>
    (println "Escriba su DNI ")
    (bind ?dni (read))
    
    (println "Escriba su PIN ")
    (bind ?pin (read))
    
    (println "Escriba el importe que desea retirar ")
    (bind ?dinero (read))
    
    (assert (Usuario (DNI ?dni) (Pin ?pin) (Dinero ?dinero)))
)
