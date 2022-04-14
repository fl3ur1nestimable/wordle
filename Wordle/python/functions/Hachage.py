import rsa  
  
publicKey, privateKey = rsa.newkeys(512) 
  
message = "hello geeks"
  
encMessage = rsa.encrypt(message.encode(),publicKey) 

  
decMessage = rsa.decrypt(encMessage, privateKey).decode() 
  


def crypt(msg):
    return rsa.encrypt(msg.encode(),publicKey)

def decrypt(msg):
    return rsa.decrypt(msg, privateKey).decode() 

