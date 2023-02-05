(deffacts iniciales
    (ubicacion A norte D)
    (ubicacion B norte E)
    (ubicacion C norte F)
    (ubicacion D norte G)
    (ubicacion E norte H)
    (ubicacion F norte I)

    (ubicacion A oeste B)
    (ubicacion B oeste C)
    (ubicacion D oeste E)
    (ubicacion E oeste F)
    (ubicacion G oeste H)
    (ubicacion H oeste I)
)

(defrule inversaNorte
    (ubicacion ?a norte ?b)
    =>
    (assert(ubicacion ?b sur ?a))
)

(defrule inversaOeste
    (ubicacion ?a oeste ?b)
    =>
    (assert(ubicacion ?b este ?a))
)

(defrule transitividad
    (declare (salience -2))
    (ubicacion ?a ?u ?b)
    (ubicacion ?b ?u ?c)
    =>
    (assert(ubicacion ?a ?u ?c))
)

(defrule noroeste
    (declare (salience -1))
    (ubicacion ?a norte ?b)
    (ubicacion ?b oeste ?c)
    =>
    (assert(ubicacion ?a noroeste ?c))
    (assert(ubicacion ?c sureste ?a))
)

(defrule noreste
    (declare (salience -1))
    (ubicacion ?a norte ?b)
    (ubicacion ?b este ?c)
    =>
    (assert(ubicacion ?a noreste ?c))
    (assert(ubicacion ?c suroeste ?a))
)

(defrule inicio
    (declare (salience -3))
    ?f1 <- (situacion ?x ?y)
    (ubicacion ?x ?u ?y)
    =>
    (printout t ?x " esta al " ?u " de " ?y crlf)
    (retract ?f1)
)

(deffacts pruebaCiudades
    (situacion I A)
)