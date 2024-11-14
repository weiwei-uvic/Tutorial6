using UnityEngine;
using UnityEngine.UIElements;

public class MessageRW : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created

    public SerialController serialController;
    private bool isRegion1 = false;
    private bool isRegion2 = false;
    private bool isRegion3 = false;
    private bool isRegion4 = false;
    void Start()
    {
        serialController = GameObject.Find("SerialController").GetComponent<SerialController>();
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 objecPosition = transform.position;
        // check which region is the game object
        // Check if the position is between (0,0) and (10,10)
        if (objecPosition.x >= 0 && objecPosition.x <= 10 && objecPosition.y >= 0 && objecPosition.y <= 10 &&!isRegion1)
        {
            Debug.Log("The GameObject is in region 1");
            isRegion1 = true;
            isRegion2 = false;
            isRegion3 = false;
            isRegion4 = false;
            serialController.SendSerialMessage("1");
        }
        else if (objecPosition.x >= 0 && objecPosition.x <= 10 && objecPosition.y <  0 && objecPosition.y > -10 && !isRegion2)
        {
            Debug.Log("The GameObject is in region 2");
            isRegion2 = true;
            isRegion1 = false;
            isRegion3 = false;
            isRegion4 = false;
            serialController.SendSerialMessage("2");
        }
        else if (objecPosition.x < 0 && objecPosition.x > -10 && objecPosition.y < 0 && objecPosition.y > -10 && !isRegion3)
        {
            Debug.Log("The GameObject is in region 3");
            isRegion3 = true;
            isRegion1 = false;
            isRegion2 = false;
            isRegion4 = false;
            serialController.SendSerialMessage("3");
        }
        else if (objecPosition.x < 0 && objecPosition.x > -10 && objecPosition.y > 0 && objecPosition.y < 10 && !isRegion4)
        {
            Debug.Log("The GameObject is in region 4");
            isRegion4 = true;
            isRegion1 = false;
            isRegion2 = false;
            isRegion3 = false;
            serialController.SendSerialMessage("4");
        }
    }
}
