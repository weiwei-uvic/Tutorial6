using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class MyMessageListener : MonoBehaviour
{


    public float speed;

    private float movement;
    // Use this for initialization
    void Start()
    {

    }
    // Update is called once per frame
    void Update()
    {
    }
    // Invoked when a line of data is received from the serial device.
    void OnMessageArrived(string msg)
    {
        //Debug.Log("Arrived: " + msg);
        movement = speed * Time.deltaTime;
        MoveObject(msg);
    }
    // Invoked when a connect/disconnect event occurs. The parameter 'success'
    // will be 'true' upon connection, and 'false' upon disconnection or
    // failure to connect.
    void OnConnectionEvent(bool success)
    {
        Debug.Log(success ? "Device connected" : "Device disconnected");
    }


    //////////////////////////////////////////////////
    /////// Following codes added by Wei//////////////
    //////////////////////////////////////////////////
    void MoveObject(string joystickDir)
    {

        joystickDir = joystickDir.Trim();
        switch (joystickDir)
        {
            case "LEFT":
                transform.Translate(Vector3.left* movement);
                break;
            case "RIGHT":
                transform.Translate(Vector3.right * movement);
                break;
            case "UP":
                transform.Translate(Vector3.up * movement);
                break;
            case "DOWN":
                transform.Translate(Vector3.down * movement);
                break;
            default:
                Debug.Log(joystickDir);
                break;
        }
    }

}