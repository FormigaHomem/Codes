async function debug(page){
    page.once('domcontentloaded', () => console.info('✅ DOM is ready'));

    // Emitted when the page is fully loaded
    page.once('load', () => console.info('✅ Page is loaded'));

    // Emitted when the page attaches a frame
    page.on('frameattached', () => console.info('✅ Frame is attached'));

    // Emitted when a frame within the page is navigated to a new URL
    page.on('framenavigated', () => console.info('👉 Frame is navigated'));

    // Emitted when a script within the page uses `console.timeStamp`
    page.on('metrics', data => console.info(`👉 Timestamp added at ${data.metrics.Timestamp}`));

    // Emitted when a script within the page uses `console`
    page.on('console', message => console.info(`👉 Console message ${message.text()}`));

    // Emitted when the page emits an error event (for example, the page crashes)
    page.on('error', error => console.error(`❌ ${error}`));

    // Emitted when a script within the page has uncaught exception
    page.on('pageerror', error => console.error(`❌ ${error}`));

    // Emitted when a script within the page uses `alert`, `prompt`, `confirm` or `beforeunload`
    page.on('dialog', async dialog => {
        console.info(`👉 ${dialog.message()}`);
        await dialog.dismiss(); 
    } ) 
}
