package breeze.pvz.cheater;

import breeze.pvz.cheater.gui.ToolGUI;
import breeze.pvz.cheater.utils.PVZHooker;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Main {
    public static void main(String[] args) {
        // 显示窗口
        final ToolGUI toolGUI = new ToolGUI();
        if (PVZHooker.isRunning()) {
            toolGUI.running_status.setText("运行状态:成功运行!");
            toolGUI.running_status.setForeground(Color.decode("#009688"));
        } else  {
            toolGUI.running_status.setText("运行状态:无法运行!");
            toolGUI.running_status.setForeground(Color.RED);
        }
        toolGUI.alter_sunshine.addActionListener(e -> PVZHooker.infinitSunshine(true));
        toolGUI.alter_coin.addActionListener(e -> PVZHooker.infinitCoin(true));


        final JFrame jFrame = new JFrame("植物大战僵尸辅助");
        jFrame.setContentPane(toolGUI.basicPanel);
        // 设置窗口参数
        jFrame.setSize(600,600);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

    }
}
