"""specs_s38082.py - cascade s8 batch 38082. cdecl(void). All 54 callees (constructors with three zero arguments and destructors, thiscall on stack objects) are hooks that log (address, ecx relative to the first object's address, arguments): the
objects live in the function's own frame, so only relative addresses are comparable. Each hook pops its callee's `ret N`."""
from pilot import S
from recruits_util import clear_hooks

CALLEES = {4506576: 3, 4506624: 0, 4507952: 3, 4508272: 0, 4515536: 3, 4515584: 0, 4516096: 3, 4516208: 0, 4477392: 3, 4477744: 0, 4517360: 3, 4517408: 0, 4528544: 3, 4528640: 0, 4532112: 3, 4532160: 0, 4532624: 3, 4532688: 0, 4533968: 3, 4534144: 0, 4450704: 3, 4450848: 0, 4448656: 3, 4447856: 0, 4539888: 3, 4539936: 0, 4486720: 3, 4487376: 0, 4496704: 3, 4496768: 0, 4540800: 3, 4541104: 0, 4543280: 3, 4543440: 0, 4551152: 3, 4551312: 0, 4563008: 3, 4563168: 0, 4564272: 3, 4564384: 0, 4566416: 3, 4566544: 3, 4568160: 3, 4568272: 0, 4472640: 3, 4472864: 0, 4499648: 3, 4499760: 0, 4502288: 3, 4502976: 0, 4447808: 3, 4463504: 3, 4463616: 0}


def _g43db70(c):
    clear_hooks(c)
    e = c.emu
    base = []

    def mk(addr, n):
        def h(em, res_):
            cx = em.reg('ecx')
            if not base:
                base.append(cx)
            em.calllog.append(('call', addr, cx - base[0]) + tuple(em.arg32(i) for i in range(n)))
            em.ret(eax=0, argbytes=4 * n)
        return h
    for a, n in CALLEES.items():
        e.hook(a, mk(a, n))
    return []


S(0x43db70, 'GUESS static init of helper objects', 'cdecl', None, ret=None, gen=_g43db70, note='batch38082')
