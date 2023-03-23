import cv2
import numpy as np

# Charger les images
img1 = cv2.imread('../Image_Pairs/torb_small1.png')
img2 = cv2.imread('../Image_Pairs/torb_small2.png')

# Appliquer une transformation géométrique à l'image 2

M = np.float32([[10, 6, 0], [0, -10, 60]])  # Exemple de translation
img2_transformee = cv2.warpAffine(img2, M, (img2.shape[1], img2.shape[0]))

"""
# Initialiser le détecteur et le descripteur ORB
orb = cv2.ORB_create()

# Extraire des points d'intérêt et des descripteurs pour les deux images
kp1, des1 = orb.detectAndCompute(img1, None)
kp2, des2 = orb.detectAndCompute(img2_transformee, None)
"""
# Initialiser le détecteur et le descripteur KAZE
kaze = cv2.KAZE_create()

# Extraire des points d'intérêt et des descripteurs pour les deux images
kp1, des1 = kaze.detectAndCompute(img1, None)
kp2, des2 = kaze.detectAndCompute(img2_transformee, None)

# Effectuer l'appariement des descripteurs entre les deux images à l'aide de la correspondance de Hamming
bf = cv2.BFMatcher(cv2.NORM_HAMMING, crossCheck=True)
matches = bf.match(des1, des2)

# Calculer la qualité des appariements en comparant les positions des points d'intérêt appariés avec les positions réelles des points d'intérêt de l'image de référence
distances = [m.distance for m in matches]
qualite = sum(distances) / len(distances)

print("La qualité des appariements est de : ", qualite)