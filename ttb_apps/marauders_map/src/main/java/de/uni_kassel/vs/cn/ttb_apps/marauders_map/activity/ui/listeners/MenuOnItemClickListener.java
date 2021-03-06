package de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.ui.listeners;

import android.content.Intent;
import android.os.Build;
import android.view.View;
import android.widget.AdapterView;

import com.github.ros_java.marauders_map.R;

import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.MapScreen;
import de.uni_kassel.vs.cn.ttb_apps.marauders_map.activity.MaraudersMap;

/**
 * Created by marci on 17.10.15.
 */
public class MenuOnItemClickListener implements AdapterView.OnItemClickListener {

    private MaraudersMap maraudersMap;

    /**
     * MainMenu functionality
     * @param adapterView
     * @param view
     * @param i
     * @param l
     */
    @Override
    public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
        if(l >= 0 && l < adapterView.getResources().getStringArray(R.array.menu_options).length) {
            switch ((int) l) {
                // Karte öffnen
                case 0:
                    Intent intent = new Intent(maraudersMap,MapScreen.class);
                    while (maraudersMap.isInitFinished() == false) {
                        try {
                            Thread.sleep(50);
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    maraudersMap.startActivity(intent);
                    break;
                // Neue Karte laden
                case 1:
                    getMaraudersMap().getTalker().getCurrentCommands().add("load_map");
                    break;
                case 2:
                    getMaraudersMap().getTalker().getCurrentCommands().add("show_stats");
                    break;
                case 3:
                    if (android.os.Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN){
                        getMaraudersMap().finishAffinity();
                    } else {
                        getMaraudersMap().finish();
                    }
                    System.exit(0);
                    break;
                default:
                    //Log MemoryCorruption
                    System.err.println("Memory Corrupt!!");
            }
        }
    }

    public MaraudersMap getMaraudersMap() {
        return maraudersMap;
    }

    public void setMaraudersMap(MaraudersMap maraudersMap) {
        this.maraudersMap = maraudersMap;
    }
}