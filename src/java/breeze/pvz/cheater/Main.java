package breeze.pvz.cheater;

import breeze.pvz.cheater.gui.ToolGUI;
import breeze.pvz.cheater.utils.PVZHooker;

import javax.swing.*;
import java.awt.*;
import java.util.Timer;
import java.util.TimerTask;

public class Main {

    private static boolean noCd = false;
    private static boolean infinitSunshine = false;

    public static void main(String[] args) {
        // 显示窗口
        final ToolGUI toolGUI = new ToolGUI();

        Timer timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                refreshStatus(toolGUI);
            }
        }, 0, 5000);

        // 无冷却线程
        new Thread(() -> {
            while (true) {
                try {
                    if (noCd) {
                        PVZHooker.clearCD();
                    }
                    if (infinitSunshine) {
                        PVZHooker.infinitSunshine(9990);
                    }
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    System.out.println(e);
                }
            }
        }).start();

        // 刷新状态
        toolGUI.refreshStatus.addActionListener(e -> refreshStatus(toolGUI));

        // 阳光
        toolGUI.alter_sunshine.addActionListener(e -> PVZHooker.infinitSunshine(9990));
        toolGUI.clearSunshine.addActionListener(e -> PVZHooker.infinitSunshine(0));

        // 金币
        toolGUI.alter_coin.addActionListener(e -> PVZHooker.infinitCoin(99999999));
        toolGUI.clearCoin.addActionListener(e -> PVZHooker.infinitCoin(0));

        // 肥料
        toolGUI.alterFertilizer.addActionListener(e -> PVZHooker.alterFertilizer(10999));
        toolGUI.clearFertilizer.addActionListener(e -> PVZHooker.alterFertilizer(1000));

        // 智慧树肥料
        toolGUI.alterTreeFertilizer.addActionListener(e -> PVZHooker.alterTreeFertilizer(10999));
        toolGUI.clearTreeFertilizer.addActionListener(e -> PVZHooker.alterTreeFertilizer(1000));

        // 除草剂
        toolGUI.alterHerbicide.addActionListener(e -> PVZHooker.alterherbicide(10999));
        toolGUI.clearHerbicide.addActionListener(e -> PVZHooker.alterherbicide(1000));

        // 智慧树高度
        toolGUI.alterTreeHight.addActionListener(e -> PVZHooker.alterTreeHeight(100));
        toolGUI.declineTreeHeight.addActionListener(e -> PVZHooker.alterTreeHeight(-100));

        // 修改巧克力数量
        toolGUI.alterQKL.addActionListener(e -> PVZHooker.alterChocolate(10999));
        toolGUI.clearQKL.addActionListener(e -> PVZHooker.alterChocolate(1000));

        // 无冷却时间
        toolGUI.chkNoCD.setSelected(noCd);
        toolGUI.chkNoCD.addItemListener(e -> {
            final JCheckBox source = (JCheckBox) e.getSource();
            noCd = source.isSelected();
        });

        toolGUI.infinitSunshine.setSelected(noCd);
        toolGUI.infinitSunshine.addItemListener(e -> {
            final JCheckBox source = (JCheckBox) e.getSource();
            infinitSunshine = source.isSelected();
        });


        final JFrame jFrame = new JFrame("植物大战僵尸辅助");
        jFrame.setContentPane(toolGUI.basicPanel);
        // 设置窗口参数
        jFrame.setSize(600, 600);
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

    }

    private static void refreshStatus(ToolGUI toolGUI) {
        if (PVZHooker.isRunning()) {
            toolGUI.running_status.setText("运行状态:成功运行!");
            toolGUI.running_status.setForeground(Color.decode("#009688"));
        } else {
            toolGUI.running_status.setText("运行状态:无法运行!");
            toolGUI.running_status.setForeground(Color.RED);
        }
    }
}
