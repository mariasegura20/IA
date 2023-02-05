(deffunction aumentarPresion (?p ?t1)
    (while (> ?t1 35)
        (bind ?p (+ ?p 1))
        (bind ?t1 (- ?t1 5))
    )
    (return ?p)
)

(deffunction decrementarTemperatura (?t1 ?t2)
    (if (> ?t2 ?t1) then
        (bind ?t2 (- ?t2 ?t1))
    )
)

(deftemplate Valvula
    (field Nombre)
    (field Estado (allowed-values Abierta Cerrada) (default Cerrada))
    (field Presion (default 0))
    (field T1 (default 0))
    (field T2 (default 0))
)

(deffacts iniciales
    (Valvula (Nombre Entrada) (T1 101) (T2 35) (Presion 1))
    (Valvula (Nombre Salida) (T1 101) (T2 155) (Presion 5))
    (Valvula (Nombre Pasillo1) (T1 99) (T2 37) (Estado Cerrada))
)

(defrule R1
    ?x <- (Valvula (Estado Abierta) (Presion 5))
    =>
    (modify ?x (Estado Cerrada) (Presion 0))
)

(defrule R2
    ?x <- (Valvula (Estado Cerrada) (Presion ?p) (T1 ?t1))
    (test (< ?p 10))
    (test (> ?t1 35))
    =>
    (modify ?x (Estado Abierta) (Presion (aumentarPresion ?p ?t1)))
)

(defrule R3
    ?x <- (Valvula (Nombre ?v1) (T2 ?t2) (Estado ?estado1))
    ?y <- (Valvula (Nombre ?v2) (T1 ?t1) (T2 ?t2) (Estado ?estado2))
    (test (neq ?v1 ?v2))
    (test (< ?t1 ?t2))
    =>
    (modify ?y(T2 (decrementarTemperatura ?t1 ?t2)) (Estado Abierta))
    (modify ?x(Estado Abierta))
)