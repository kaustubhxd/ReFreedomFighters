from pilot import S
from recruits_util import clear_hooks, obj, pystub

def gen(c):
    clear_hooks(c)
    e=c.emu
    sink=obj(c, 0x30, {0x2c:pystub(c, 2, pop=0)})
    logger=obj(c, 0x30, {0x20:pystub(c, 2, ret=sink, pop=8, this=True)})
    e.w32(0x700390,logger)
    def terminate(em,r):
        em.calllog.append(('exit',em.arg32(0)))
        em.stop('planned process termination',ok=True)
    # IAT address 0x676394 is exit; do not return into the next function.
    e.stub_import('_exit',terminate)
    return []
S(0x42461c,'GUESS fatal diagnostic and exit','cdecl',None,ret=None,gen=gen,note='batch34167; planned stop at process termination')
