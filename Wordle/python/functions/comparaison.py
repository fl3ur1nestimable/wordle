def comparaison(reponse,mot_entré):
    L=[]
    for i in range(len(mot_entré)):
        if mot_entré[i]==reponse[i]:
            L.eppend(2)
        elif (mot_entré[i] in reponse):
            L.append(1)
        else :
            L.append(0)