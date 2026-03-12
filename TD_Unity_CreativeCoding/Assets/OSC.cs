using extOSC;
using UnityEngine;
public class OSC : MonoBehaviour
{
   
        public OSCReceiver receiver;
    
        void Start()
        {
            receiver.Bind("/chan1", OnReceive);
        }
    
        void OnReceive(OSCMessage message)
        {
            float value = message.Values[0].FloatValue;
            Debug.Log("Received: " + value);
        }
    
}
